package com.chuckvalenza.SwordFighter;

import android.app.Activity;
import android.content.Intent;
import android.os.Handler;
import android.os.Bundle;

public class SplashActivity extends Activity {
	private final int TIME_DELAY_MS = 3000;

	Runnable mRunnable = new Runnable() {
			@Override
			public void run() {
				Intent intent = new Intent(SplashActivity.this, MenuActivity.class);
				startActivity(intent);
				finish();
			}
		};

	@Override
	protected void onCreate(Bundle savedInstanceState) {
		super.onCreate(savedInstanceState);
		setContentView(R.layout.activity_splash);

		new Handler().postDelayed(mRunnable, TIME_DELAY_MS);
	}
}
