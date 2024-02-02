/*
 * Last changed at upstream commit f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * https://github.com/espressif/esp-zigbee-sdk/commit/f9cc2dccd1062ffdf8f9e034d227fe83c0a1712e
 * Upstream date: 2024-02-02 22:17:34 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.1.0(5362d771)
 * Source: libesp_zb_cli_command -> zb_esp_cli_cmd_bdb.o -> zb_cli_register_bdb_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void zb_cli_register_bdb_cmd(void)

{
  int iVar1;
  undefined *puStack_2c;
  char *pcStack_28;
  undefined4 uStack_24;
  code *pcStack_20;
  undefined4 *puStack_1c;
  undefined4 uStack_18;
  undefined4 uStack_14;
  
  bdb_args = arg_lit0(&_LC16,"radio","ask device to turn on/off radio");
  DAT_00014864 = arg_str0(&_LC115,&_LC114,"<role>",
                          "Set or get the Zigbee role of a device. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_0001486c = arg_str0(&_LC119,"extpanid","<extpanid>",
                          "Set or get the Zigbee Extended Pan ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00014870 = arg_str0(&_LC123,"panid","<panid>",
                          "Set or get the Zigbee PAN ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00014868 = arg_str0(&_LC127,"network type","<type>",
                          "Set network type as centralized(default) or distributed (router only)");
  DAT_00014874 = arg_lit0(&_LC130,"start","Start the commissioning process");
  DAT_0001487c = arg_lit0(&_LC133,"network state","Set network state(open/close)");
  DAT_00014878 = arg_str0(&_LC137,"commissioning","<mode>","Set network commissioning mode");
  DAT_00014880 = arg_str0(&_LC14,"channel","<channel>","Set or get 802.15.4 channel");
  DAT_00014884 = arg_lit0(&_LC143,"channel mask","Set or get 802.15.4 channel mask");
  DAT_00014888 = arg_str0(&_LC147,&_LC146,"<ic_operation>",
                          "Set install code on the device, add information about the install code on the trust center, set the trust center install code policy."
                         );
  DAT_0001488c = arg_strn(0,0,&_LC149,0,1,"Set install code on the device.");
  DAT_00014890 = arg_strn(0,0,&_LC149,0,1,"Set eui64 of the device install code on.");
  DAT_00014894 = arg_str0(&_LC154,"legacy","<enable/disable>",
                          "Enable or disable the legacy device support");
  DAT_00014898 = arg_str0(&_LC158,"nwk key","<key>","Set network key");
  DAT_0001489c = arg_str0(&_LC162,"factory_reset","<level>","factory reset");
  DAT_000148a0 = arg_str0(&_LC166,"childmax","<max_children>","Set max children");
  DAT_000148a4 = arg_end(0xd);
  uStack_24 = 0;
  uStack_18 = 0;
  uStack_14 = 0;
  puStack_2c = &_LC167;
  pcStack_28 = "ZigBee bdb command";
  pcStack_20 = zb_cli_bdb_cmd_cb;
  puStack_1c = &bdb_args;
  iVar1 = esp_console_cmd_register(&puStack_2c);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x4e7,
             "zb_cli_register_bdb_cmd","esp_console_cmd_register(&bdb_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

