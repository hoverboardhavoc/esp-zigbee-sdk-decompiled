/*
 * Last changed at upstream commit 2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * https://github.com/espressif/esp-zigbee-sdk/commit/2fe15bae2e4382ac99f249a0934066f5d5a5c684
 * Upstream date: 2024-03-08 17:10:04 +0800
 * Upstream subject: esp-zigbee-sdk: release/v1.2.0(9d7e9ff2)
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
  undefined *puStack_24;
  char *pcStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  undefined4 *puStack_14;
  
  bdb_args = arg_lit0(&_LC22,"radio","ask device to turn on/off radio");
  DAT_00014840 = arg_str0(&_LC121,&_LC120,"<role>",
                          "Set or get the Zigbee role of a device. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00014848 = arg_str0(&_LC125,"extpanid","<extpanid>",
                          "Set or get the Zigbee Extended Pan ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_0001484c = arg_str0(&_LC129,"panid","<panid>",
                          "Set or get the Zigbee PAN ID value. [Setting only before bdb start. Reading only after bdb start.]"
                         );
  DAT_00014844 = arg_str0(&_LC133,"network type","<type>",
                          "Set network type as centralized(default) or distributed (router only)");
  DAT_00014850 = arg_lit0(&_LC136,"start","Start the commissioning process");
  DAT_00014858 = arg_lit0(&_LC139,"network state","Set network state(open/close)");
  DAT_00014854 = arg_str0(&_LC143,"commissioning","<mode>","Set network commissioning mode");
  DAT_0001485c = arg_str0(&_LC20,"channel","<channel>","Set or get 802.15.4 channel");
  DAT_00014860 = arg_lit0(&_LC149,"channel mask","Set or get 802.15.4 channel mask");
  DAT_00014864 = arg_str0(&_LC153,&_LC152,"<ic_operation>",
                          "Set install code on the device, add information about the install code on the trust center, set the trust center install code policy."
                         );
  DAT_00014868 = arg_strn(0,0,&_LC155,0,1,"Set install code on the device.");
  DAT_0001486c = arg_strn(0,0,&_LC155,0,1,"Set eui64 of the device install code on.");
  DAT_00014870 = arg_str0(&_LC160,"legacy","<enable/disable>",
                          "Enable or disable the legacy device support");
  DAT_00014874 = arg_str0(&_LC164,"nwk key","<key>","Set network key");
  DAT_00014878 = arg_str0(&_LC168,"factory_reset","<level>","factory reset");
  DAT_0001487c = arg_str0(&_LC172,"childmax","<max_children>","Set max children");
  DAT_00014880 = arg_end(0xd);
  puStack_24 = &_LC0;
  pcStack_20 = "ZigBee bdb command";
  uStack_1c = 0;
  pcStack_18 = zb_cli_bdb_cmd_cb;
  puStack_14 = &bdb_args;
  iVar1 = esp_console_cmd_register(&puStack_24);
  if (iVar1 == 0) {
    return;
  }
  _esp_error_check_failed
            ("/home/xieqinan/ESP/esp-zboss/components/zboss_cli_command/zb_esp_cli_cmd_bdb.c",0x56e,
             "zb_cli_register_bdb_cmd","esp_console_cmd_register(&bdb_cmd)");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

