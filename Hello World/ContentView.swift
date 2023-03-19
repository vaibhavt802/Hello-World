//
//  ContentView.swift
//  Hello World
//
//  Created by Vaibhav Thakur on 09/03/23.
//

import SwiftUI

struct ContentView: View {
    
    @State var scheme: String = ""
    
    var body: some View {
        VStack {
            Image(systemName: "globe")
                .imageScale(.large)
                .foregroundColor(.accentColor)
            Text("Hello, world!")
            Text(scheme)
                .foregroundColor(.red)
        }
        .onAppear(perform: self.selectedScheme)
        .padding()
    }
    
    func selectedScheme() {
        #if Dev
            scheme = "Dev"
        #elseif QA
            scheme = "QA"
        #elseif UAT
            scheme = "UAT"
        #elseif Prod
            scheme = "Prod"
        #endif
    }
}

struct ContentView_Previews: PreviewProvider {
    static var previews: some View {
        ContentView()
    }
}
