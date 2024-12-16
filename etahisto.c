void etahisto(){

	TH1F *h_eta = new TH1F("h_eta","pseudo rapidity distribution",100,-2,2);
	TFile *f = new TFile("event_1.root");
	TTree *t = (TTree*)f->Get("t1");

	Float_t eta;
	Int_t npi;

	t->SetBranchAddress("eta",&eta);
	t->SetBranchAddress("npi",&npi);
	
	Int_t n = (Int_t)t->GetEntries();

	for(Int_t i=0; i<n; i++){
		
		t-> GetEntry(i);
		for(Int_t j=0; j<=npi; j++){
			h_eta->Fill(eta);	
		}
	}	
	
	TCanvas *c1 = new TCanvas();
	h_eta->Draw("cloz");
	c1->SaveAs("eta.png");

	f->Close();

}
