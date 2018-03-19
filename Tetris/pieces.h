#ifndef _PIECES_
#define _PIECES_

class Pieces
{
public:
	// Return block type inside pice
	// 0: no block
	// 1: normal block
	// 2: pivot block
	int getBlockType(int piece, int rotation, int x, int y);
	
	// Horizontal piece inititial position
	int getXInitialPosition(int piece, int rotation);

	// Horizontal piece vertical position
	int getYInitialPosition(int piece, int rotation);

	// Pieces definition : kind / rotation / horizontal / vertical
	char pieces[7][4][5][5] =
	{
		// Square
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
			},
		   {
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
		   },
		   {
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
		   },
		   {
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 2, 1, 0 },
				{ 0, 0, 1, 1, 0 },
				{ 0, 0, 0, 0, 0 }
		   }
		},

		// I
		{
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 1, 2, 1, 1 },
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 0, 0, 0 }
			},
			{
				{ 0, 0, 0, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 2, 0, 0 },
				{ 0, 0, 1, 0, 0 },
				{ 0, 0, 1, 0, 0 }
			 },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 1, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  }
		,
		// L
	  {
		  {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		  },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  },
		// L mirrored
	  {
		  {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		  },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  },
		// N
	  {
		  {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		  },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },



	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  },
		// N mirrored
	  {
		  {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 0, 1, 0 },
			{ 0, 0, 0, 0, 0 }
		  },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 1, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 0, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 1, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  },
		// T
	  {
		  {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
		  },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   },
	   {
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 1, 0, 0 },
			{ 0, 1, 2, 1, 0 },
			{ 0, 0, 0, 0, 0 },
			{ 0, 0, 0, 0, 0 }
	   }
	  }
	};

	// Initial position : kind / rotation / position
	int piecesInitialPosition[7][4][2] =
	{
		/* Square */
		{
			{ -2, -3 },
	{ -2, -3 },
	{ -2, -3 },
	{ -2, -3 }
		},
		/* I */
	  {
		  { -2, -2 },
	{ -2, -3 },
	{ -2, -2 },
	{ -2, -3 }
	  },
		/* L */
	  {
		  { -2, -3 },
	{ -2, -3 },
	{ -2, -3 },
	{ -2, -2 }
	  },
		/* L mirrored */
	  {
		  { -2, -3 },
	{ -2, -2 },
	{ -2, -3 },
	{ -2, -3 }
	  },
		/* N */
	  {
		  { -2, -3 },
	{ -2, -3 },
	{ -2, -3 },
	{ -2, -2 }
	  },
		/* N mirrored */
	  {
		  { -2, -3 },
	{ -2, -3 },
	{ -2, -3 },
	{ -2, -2 }
	  },
		/* T */
	  {
		  { -2, -3 },
	{ -2, -3 },
	{ -2, -3 },
	{ -2, -2 }
	  },
	};

};
#endif // _PIECES_