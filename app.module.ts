import { NgModule } from '@angular/core';
import { BrowserModule } from '@angular/platform-browser';
// import { ReactiveFormsModule } from '@angular/forms';
// import { HttpClientModule } from '@angular/common/http';
import { AppComponent } from './app.component';
import { RepeatDirective } from './repeat.directive';
import { ProductListComponent } from './product-list/product-list.component';
// import { AppRoutingModule } from './app-routing.module';
// import { WelcomeComponent } from './welcome/welcome.component';
// import { LoginComponent } from './login/login.component';
// import { AppDirective } from './app.directive';
@NgModule({
    imports: [BrowserModule],
    declarations: [AppComponent, RepeatDirective, ProductListComponent],
    providers: [],
    bootstrap: [AppComponent]
})
export class AppModule { }
