class Solution {

// Errichto's Solution - O (H + W)
// https://www.youtube.com/watch?v=nmaI2RC7SWU&list=PLl0KD3g-oDOHElCF7S7q6CRGz1qG8vQkS&index=21

// This Solution - O (H log W)

public:
	int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {

		pair <int,int> dims = BinaryMatrix.dimensions();
		int n=dims.first,m=dims.second;

		int l=0,r=m-1;
		int mid,res,x;
		bool tmp=0;
		while(l<=r)
		{
			mid=r-(r-l)/2;
			tmp=0;
			for(int i=0;i<n;i++)
			{
				x=BinaryMatrix.get(i, mid);
				if(x==1)
				{
					tmp=1;
					break;
				}
			}
			if(tmp)
			{
				res=mid;
				r=mid-1;
			}
			else
			l=mid+1;
		}
		return res;

	}

}