// Import the functions you need from the SDKs you need
import { initializeApp } from "firebase/app";
import { getAnalytics } from "firebase/analytics";
import { getFirestore } from 'firebase/firestore'
// TODO: Add SDKs for Firebase products that you want to use
// https://firebase.google.com/docs/web/setup#available-libraries

// Your web app's Firebase configuration
// For Firebase JS SDK v7.20.0 and later, measurementId is optional
const firebaseConfig = {
  apiKey: process.env.NEXT_PUBLIC_FIREBASE_API_KEY,
  authDomain: "loopnet-eb18d.firebaseapp.com",
  projectId: "loopnet-eb18d",
  storageBucket: "loopnet-eb18d.appspot.com",
  messagingSenderId: "281996185921",
  appId: "1:281996185921:web:28378e7c95be473ea151c0",
  measurementId: "G-2WZL7C9FMP"
};

// Initialize Firebase
export const app = initializeApp(firebaseConfig);

export const db = getFirestore(app);
const analytics = getAnalytics(app);