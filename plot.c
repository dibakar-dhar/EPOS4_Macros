void plot() {
    TCanvas *c1 = new TCanvas("c1","A Simple Graph Example",200,10,700,500);
 
    c1->SetGrid();
    ifstream in;
    in.open("event-1.dat");
 	Int_t n;
 	in >> n;
 	std::cout<< n << std::endl;
 	Float_t x[n], y[n], z[n];
 	for (Int_t i=0;i<n;i++) {
    	in >> x[i] >> y[i] >> z[i];
    	std::cout<< i << "	" << x[i] << "	"<< y[i]<< "	" << z[i] << std::endl;
   }
 	
 	TGraph *gr = new TGraph(n,x,y);
   	gr->SetLineColor(2);
   	gr->SetLineWidth(4);
   	gr->SetMarkerColor(4);
   	gr->SetMarkerStyle(21);
   	gr->SetTitle("Rapidity Distribution");
   	gr->GetXaxis()->SetTitle("Rapidity");
   	gr->GetYaxis()->SetTitle("Number of Particles");
   	gr->Draw("ACP");
 
   	// TCanvas::Update() draws the frame, after which one can change it
   	c1->Update();
   	c1->GetFrame()->SetBorderSize(12);
   	c1->Modified();
}
