//==========================================
void data()
{
    //=========================================
    TFile *f=new TFile("test.root"); // opens the root file
    TTree *t=(TTree*)f->Get("teposevent");
    //==========================================
    Int_t np,id[200000];
    Float_t px[200000], py[200000], pz[200000], e[200000];
    //==========================================
    t->SetBranchAddress("np",&np);
    t->SetBranchAddress("px",px);
    t->SetBranchAddress("py",py);
    t->SetBranchAddress("pz",pz);
    t->SetBranchAddress("e",e);
    t->SetBranchAddress("id",id);
    //==========================================
    ofstream myfile,test;
    myfile.open ("output.dat");
    //==========================================
    Int_t nentries=(Int_t)t->GetEntries();
    for (Int_t i=0;i<nentries;i++) {
    t->GetEntry(i);
	myfile << (i+1) <<"\t" << np << endl;
		for(Int_t j=0;j<np;j++){
			myfile<< id[j] << "\t" << px[j] <<"\t"<< py[j] <<"\t" << pz[j]<<"\t" << e[j] <<endl;
		}
    }
    //==========================================
cout<< "Completed Thank you" <<endl;
myfile.close();
}
