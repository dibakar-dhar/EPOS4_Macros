//==========================================
void eta_extractor()
{
    //=========================================
    TFile *f=new TFile("pp-2t-hyd-hlle.root"); // opens the root file
    TTree *t=(TTree*)f->Get("teposevent");
    //==========================================
    Int_t np,id[200000];
    Int_t k;
    Float_t px[200000], py[200000], pz[200000], e[200000];
    Float_t eta[200000];
    //==========================================
    t->SetBranchAddress("np",&np);
    t->SetBranchAddress("px",px);
    t->SetBranchAddress("py",py);
    t->SetBranchAddress("pz",pz);
    t->SetBranchAddress("e",e);
    t->SetBranchAddress("id",id);
    //==========================================
    ofstream myfile;
    myfile.open("output.dat");
    //==========================================
    Int_t nentries=(Int_t)t->GetEntries();
    for (Int_t i=0;i<100000;i++) {    // i is counting event numbers
    	t->GetEntry(i);
    	k=0;   // k is counting pions
		for(Int_t j=0;j<np;j++){    // j is counting total no. of particles
			if((abs(id[j])==120)||(abs(id[j])==110)){
				eta[k] = atanh(pz[j]/sqrt(px[j]*px[j]+py[j]*py[j]+pz[j]*pz[j]+e[j]*e[j]));
				k=k+1;
			}
		}
		myfile.width(6);
		myfile <<i+1<<"\t \t"<<(k+1)<<endl;
		myfile.precision(5);
		for(Int_t m=0;m<=k;m++){
			myfile << (m+1) << "\t \t"<< eta[m] <<endl;	\
		}
    }
    //==========================================
cout<< "Completed Thank you" <<endl;
myfile.close();
}






