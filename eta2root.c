//==========================================
void eta2root()
{
    //=========================================
    TFile *f=new TFile("test.root"); // opens the root file
    TTree *t=(TTree*)f->Get("teposevent");
    TFile *f1= new TFile("event_1.root","RECREATE");
    TTree *t1= new TTree("t1","eta distribution");
    //==========================================
    Int_t np,id[200000];
    Int_t k,npi;
    Float_t px[200000], py[200000], pz[200000], e[200000];
    Float_t n[200000];
    Float_t eta[200000];
    //==========================================
    t->SetBranchAddress("np",&np);
    t->SetBranchAddress("px",px);
    t->SetBranchAddress("py",py);
    t->SetBranchAddress("pz",pz);
    t->SetBranchAddress("e",e);
    t->SetBranchAddress("id",id);
    //=========================================
    t1->Branch("eta",eta,"eta[200000]/F");
    t1->Branch("npi",&npi,"npi/I");
    //==========================================
    Int_t nentries=(Int_t)t->GetEntries();
    for (Int_t i=0;i<1;i++) {    // i is counting event numbers
    	t->GetEntry(i);
    	k=0;   // k is counting pions
		for(Int_t j=0;j<np;j++){    // j is counting total no. of particles
			if((abs(id[j])==120)||(abs(id[j])==110)){
			
				n[k]= atanh(pz[j]/sqrt(px[j]*px[j]+py[j]*py[j]+pz[j]*pz[j]+e[j]*e[j]));
				k=k+1;
			}		
		}
    }
    for(Int_t m=0;m<k;m++){
    	eta[m] = n[m];
		npi=k;
    	cout << m << "\t" << eta[m] <<endl;
    }
    t1->Fill();

f1->Write();
f1->Close();
    //==========================================
cout<< "Completed Thank you" <<endl;
}







