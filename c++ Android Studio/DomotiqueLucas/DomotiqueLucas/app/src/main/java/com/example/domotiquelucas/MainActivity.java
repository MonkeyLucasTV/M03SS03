package com.example.domotiquelucas;

import androidx.appcompat.app.AppCompatActivity;

import android.os.Bundle;
import android.view.ContextMenu;
import android.view.View;
import android.widget.Button;
import android.widget.EditText;
import android.widget.SeekBar;
import android.widget.TextView;

import com.example.domotiquelucas.databinding.ActivityMainBinding;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'domotiquelucas' library on application startup.
    static {
        System.loadLibrary("domotiquelucas");
    }

    private ActivityMainBinding binding;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);

        binding = ActivityMainBinding.inflate(getLayoutInflater());
        setContentView(binding.getRoot());

        Button buttonMAJ = binding.buttonMAJ;
        TextView txtVwTemp = binding.textViewTemp;
        TextView txtVwPress = binding.textViewPress;
        TextView txtVwHumid = binding.textViewHumid;
        buttonMAJ.setOnClickListener(new View.OnClickListener(){
            @Override
            public void onClick(View view) {
                String temp = RecupererTemperatureSalleA7();
                txtVwTemp.setText(temp);
                String humid = RecupereHumidSallA7();
                txtVwHumid.setText(humid);
                String press = RecupererPressSallA7();
                txtVwPress.setText(press);



            }
        });

        Button buttonOn = binding.buttonOn;
        Button buttonOff = binding.buttonOff;
        buttonOn.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                AllumerLampeMulticoloreA7();
            }
        });
        buttonOff.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                EteindreLampeMulticoloreA7();
            }
        });

        Button buttonBrille = binding.buttonBrillance;
        SeekBar seekbarBrille = binding.seekBar;


        buttonBrille.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                ModifierBrillanceLampeMulticoloreA7(String.valueOf(seekbarBrille.getProgress()));
            }
        });

        SeekBar seekbarColor = binding.seekBar2;




        seekbarColor.setOnSeekBarChangeListener(new SeekBar.OnSeekBarChangeListener() {
            @Override
            public void onProgressChanged(SeekBar seekBar, int progress, boolean fromUser) {
                CouleurModifier(String.valueOf(seekbarColor.getProgress()));
            }

            @Override
            public void onStartTrackingTouch(SeekBar seekBar) {

            }

            @Override
            public void onStopTrackingTouch(SeekBar seekBar) {

            }
        });


    }

    /**
     * A native method that is implemented by the 'domotiquelucas' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String RecupererTemperatureSalleA7();

    public native String RecupererPressSallA7();

    public native String RecupereHumidSallA7();

    public native void AllumerLampeMulticoloreA7();

    public native void EteindreLampeMulticoloreA7();

    public native void ModifierBrillanceLampeMulticoloreA7(String valeur);

    public native void CouleurModifier(String valeur);


}

