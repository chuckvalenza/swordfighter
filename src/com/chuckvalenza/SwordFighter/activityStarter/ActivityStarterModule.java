package com.chuckvalenza.SwordFighter.activityStarter;

import android.app.Activity;
import android.content.ActivityNotFoundException;
import android.content.Intent;

import com.facebook.react.bridge.ActivityEventListener;
import com.facebook.react.bridge.Arguments;
import com.facebook.react.bridge.Callback;
import com.facebook.react.bridge.ReactApplicationContext;
import com.facebook.react.bridge.ReactContextBaseJavaModule;
import com.facebook.react.bridge.ReactMethod;
import com.facebook.react.bridge.WritableMap;

import com.chuckvalenza.SwordFighter.GameActivity;

public class ActivityStarterModule extends ReactContextBaseJavaModule implements ActivityEventListener {
	private static String TAG = "GameLauncher";
	private Class activity = GameActivity.class;
	WritableMap response;

	public ActivityStarterModule(ReactApplicationContext reactContext) {
		super(reactContext);
	}

	@ReactMethod
	public void startGame(Callback callback) {
		response = Arguments.createMap();

		Activity currentActivity = getCurrentActivity();
		Intent gameIntent = new Intent(getReactApplicationContext(), GameActivity.class);

		if (currentActivity == null) {
			response.putString("error", "Can't find current Activity");
			callback.invoke(response);
			return;
		}

		try {
			currentActivity.startActivity(gameIntent);
		} catch (ActivityNotFoundException e) {
			e.printStackTrace();
			response = Arguments.createMap();
			response.putString("error", "Cannot launch activity");
			callback.invoke(response);
		}
	}

	@Override
	public String getName() {
		return TAG;
	}

	@Override
	public void onActivityResult(Activity activity, int requestCode, int resultCode, Intent data) {

	}

	@Override
	public void onNewIntent(Intent intent) {

	}
}

