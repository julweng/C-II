/***************************************************************************

   SPECIAL REQUIREMENTS FOR THIS EXERCISE ONLY:

      PLEASE DO NOT SUBMIT THIS ORIGINAL FILE TO THE "AUTOMATED ASSIGNMENT
      CHECKER" OR TO THE INSTRUCTOR.
      
      PLEASE DO NOT INCLUDE "-Driver" IN THE NAME OF THE FILE YOU CREATE FOR
      THIS ASSIGNMENT SINCE I RESERVE THAT DESIGNATION FOR MY DRIVER FILES.

      Unlike all the other programming exercises, you will need to understand
      the code in this file so you can copy it into your own file, modify it,
      and test it.  Please see the complete exercise requirements in the
      assignment 7 requirements document.

   
   Thank you!

 **************************************************************************/


/*
 * Leaving the following macro defined enables the binary tree code.
 * Commenting it out enables the hash table code.  Completely remove
 * this macro and all references to it in the program you produce.
 */
#define TREE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LINE_LEN 256                 /* size of input buffer */
#define BUFFMT "%255"                /* field width for input buffer scan */

void *SafeMalloc(size_t size)
{
   void *vp;

   if ((vp = malloc(size)) == NULL)
   {
      fputs("Out of memory\n", stderr);
      exit(EXIT_FAILURE);
   }
   return(vp);
}

FILE *OpenFile(const char *fileName)
{
   FILE *fp;

   if ((fp = fopen(fileName, "r")) == NULL)
   {
      fprintf(stderr, "File %s didn't open.\n", fileName);
      perror(fileName);
      exit(EXIT_FAILURE);
   }
   return fp;
}

#ifdef TREE
/***************************************************************************
                                  (Binary Trees)
 ***************************************************************************/

#define MIN_ARGS 2                  /* fewest command line arguments */
#define FILE_ARG_IX 1               /* index of file name argument */

typedef struct Node NODE;
struct Node
{
   char *strng;                  /* points to string this node represents */
   size_t count;                 /* number of occurrences of this string */
   NODE *left, *right;           /* pointers to left and right children */
};

/*
 * BuildTree will search the binary tree at pNode for a node representing the
 * string in str.  If found, its string count will be incremented.  If not
 * found, a new node for that string will be created, put in alphabetical
 * order, and its count set to 1.  A pointer to the node for string str is
 * returned.
 */
NODE *BuildTree(NODE *pNode, char *str)
{
   if (pNode == NULL)                               /* string not found */
   {
      size_t length = strlen(str) + 1;              /* length of string */

      pNode = (NODE *)SafeMalloc(sizeof(NODE));     /* allocate a node */
      pNode->strng = (char *)SafeMalloc(length);
      memcpy(pNode->strng, str, length);            /* copy string */
      pNode->count = 1;                             /* 1st occurrence */
      pNode->left = pNode->right = NULL;            /* no subtrees */
   }
   else
   {
      int result = strcmp(str, pNode->strng);    /* compare strings */

      if (result == 0)                           /* new string == current */
         ++pNode->count;                         /* increment occurrence */
      else if (result < 0)                       /* new string < current */
         pNode->left = BuildTree(pNode->left, str);     /* traverse left */
      else                                       /* new string > current */
         pNode->right = BuildTree(pNode->right, str);   /* traverse right */
   }
   return(pNode);
}

/*  PrintTree recursively prints the binary tree in pNode alphabetically */
void PrintTree(const NODE *pNode)
{
   if (pNode != NULL)                            /* if child exists */
   {
      PrintTree(pNode->left);                    /* traverse left */
      printf("%4d  %s\n", (int)pNode->count, pNode->strng);
      PrintTree(pNode->right);                   /* traverse right */
   }
}

/*  FreeTree recursively frees the binary tree in pNode */
void FreeTree(NODE *pNode)
{
   if (pNode != NULL)                            /* if child exists */
   {
      FreeTree(pNode->left);                     /* traverse left */
      FreeTree(pNode->right);                    /* traverse right */
      free(pNode->strng);                        /* free the string */ 
      free(pNode);                               /* free the node */ 
   }
}

int main(int argc, char *argv[])
{
   char buf[LINE_LEN];                           /* word string buffer */
   char fileName[LINE_LEN];                      /* file name buffer */
   NODE *root;                                   /* pointer to root node */
   FILE *fp;

   /* Read file name from command line */
   if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
   {
      fprintf(stderr, "No file name specified on command line\n");
      return EXIT_FAILURE;
   }

   fp = OpenFile(fileName);

   /*
    * The following loop will read one string at a time from stdin
    * until EOF is reached.  For each string read the BuildTree
    * function will be called to update the tree.
    */
   for (root = NULL; fscanf(fp, BUFFMT "s", buf) != EOF;
      root = BuildTree(root, buf))
      ;
   fclose(fp);
   PrintTree(root);
   FreeTree(root);
   return(EXIT_SUCCESS);
}


#else
/***************************************************************************
                                    (Hashing)
 ***************************************************************************/

#define MIN_ARGS 3                     /* fewest command line arguments */
#define FILE_ARG_IX 1                  /* index of file name argument */
#define BINS_ARG_IX 2                  /* index of bin count argument */

typedef struct Node NODE;
struct Node                            /* type of each list node */
{
   char *strng;                        /* string for this node */
   size_t count;                       /* occurrences of this string */
   NODE *next;                         /* next node in list */
};

typedef struct                         /* type of table array elements */
{
   size_t nodes;                       /* # of list nodes for this bin */
   NODE *firstNode;                    /* 1st node in this bin's list */
} BIN;

typedef struct                         /* type of hash table descriptor */
{
   size_t bins;                        /* bins in hash table */
   BIN *firstBin;                      /* first bin */
} TABLE;

int HashFunction(const char *key, size_t bins)  /* get bin value from key */
{
   return((int)(strlen(key) % bins));  /* value is character count % bins */
}

/* CreateTable creates and initializes the hash table and its bins */
TABLE *CreateTable(size_t bins)
{
   TABLE *hashTable;
   BIN *bin, *end;

   hashTable = (TABLE *)SafeMalloc(sizeof(TABLE));   /* alloc desc struct */
   hashTable->bins = bins;                           /* how many bins */
   /* alloc bins */
   hashTable->firstBin = (BIN *)SafeMalloc(bins * sizeof(BIN));
   end = hashTable->firstBin + bins;                 /* end of bins */

   for (bin = hashTable->firstBin; bin < end; ++bin) /* initialize bins */
   {
      bin->nodes = 0;                                /* no list nodes */
      bin->firstNode = NULL;                         /* no list */
   }
   return(hashTable);
}

/*
 * BuildList will search bin bp of the list for a node representing
 * the string in str.  If found, its string count will be incremented.
 * If not found, a new node for that string will be created, put at
 * the top of the list, and its string count set to 1.
 */
void BuildList(BIN *bp, const char *str)
{
   NODE *pNode = bp->firstNode;                 /* first node in list */

   for (; pNode != NULL; pNode = pNode->next)   /* visit each node */
      if (!strcmp(pNode->strng, str))           /* if strings match... */
         break;                                 /* ...quit looking */
   if (pNode == NULL)                           /* no matching node */
   {
      size_t length = strlen(str) + 1;          /* characters in string */

      pNode = (NODE *)SafeMalloc(sizeof(NODE)); /* allocate new node */
      pNode->strng = (char *)SafeMalloc(length);   /* storage for string */
      memcpy(pNode->strng, str, length);        /* store string */
      pNode->count = 1;                         /* set string count */
      pNode->next = bp->firstNode;              /* insert new node... */
      bp->firstNode = pNode;                    /* ...first in list */
      ++bp->nodes;                              /* update node count */
   }
   else                                         /* found matching node */
      ++pNode->count;                           /* increment string count */
}

/* PrintTable prints the hash table */
void PrintTable(const TABLE *hashTable)
{
   BIN *bin, *end;

   end = hashTable->firstBin + hashTable->bins;       /* end of bins */
   for (bin = hashTable->firstBin; bin < end; ++bin)  /* visit bins */
   {
      NODE *node;
      printf("%d entries for bin %d:\n",
         (int)bin->nodes, (int)(bin - hashTable->firstBin));
      /* Visit nodes */
      for (node = bin->firstNode; node != NULL; node = node->next)
         printf("%4d  %s\n", (int)node->count, node->strng);
   }
}

/* FreeTable frees the hash table */
void FreeTable(TABLE *hashTable)
{
   BIN *bin, *end;

   end = hashTable->firstBin + hashTable->bins;       /* end of bins */
   for (bin = hashTable->firstBin; bin < end; ++bin)  /* visit bins */
   {
      NODE *node;
      for (node = bin->firstNode; node != NULL;)      /* visit nodes */
      {
         NODE *pNode = node;        /* save NODE pointer */
         node = node->next;         /* point to next node */
         free(pNode->strng);        /* free the string */
         free(pNode);               /* free the node */
      }
   }
   free(hashTable->firstBin);       /* free all bins */
   free(hashTable);                 /* free table descriptor */
}

int main(int argc, char *argv[])
{
   char buf[LINE_LEN];              /* word string buffer */
   char fileName[LINE_LEN];         /* file name buffer */
   int howManyBins;                 /* number of bins to create */
   TABLE *hashTable;                /* pointer to hash table */
   FILE *fp;

   /* Read file name from command line */
   if (argc < MIN_ARGS || sscanf(argv[FILE_ARG_IX], BUFFMT "s", fileName) != 1)
   {
      fprintf(stderr, "No file name specified on command line\n");
      return EXIT_FAILURE;
   }
   fp = OpenFile(fileName);

   /* Read bin count from command line */
   if (sscanf(argv[BINS_ARG_IX], "%d", &howManyBins) != 1)
   {
      fprintf(stderr, "No bin count specified on command line\n");
      return EXIT_FAILURE;
   }      
   hashTable = CreateTable((size_t)howManyBins);  /* allocate table array */

   /*
    * The following loop will read one string at a time from stdin until
    * EOF is reached.  For each string read the BuildList function will
    * be called to update the hash table.
    */
   while (fscanf(fp, BUFFMT "s", buf) != EOF) /* get string from file */
   {
      /* find appropriate bin */
      BIN *bin = &hashTable->firstBin[HashFunction(buf, (size_t)howManyBins)];
      BuildList(bin, buf);                   /* put string in list */
   }
   fclose(fp);
   PrintTable(hashTable);                    /* print all strings */
   FreeTable(hashTable);                     /* free the table */
   return(EXIT_SUCCESS);
}

#endif
