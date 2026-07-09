/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.debug -> aps_compat.o -> esp_zb_apsde_data_indication_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Control flow encountered bad instruction data */

void esp_zb_apsde_data_indication_handler(undefined4 *param_1)

{
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined4 uStack_38;
  undefined4 uStack_34;
  undefined4 uStack_30;
  undefined4 uStack_2c;
  undefined4 uStack_28;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  
  if (s_esp_zb_data_ind_handler == (code *)0x0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                  ,0x34,"esp_zb_apsde_data_indication_handler",0x10000);
  }
  else if (param_1 != (undefined4 *)0x0) {
    local_40 = *param_1;
    uStack_3c = param_1[1];
    uStack_38 = param_1[2];
    uStack_34 = param_1[3];
    uStack_30 = param_1[4];
    uStack_2c = param_1[5];
    uStack_28 = param_1[6];
    uStack_24 = param_1[7];
    uStack_20 = param_1[8];
    uStack_1c = param_1[9];
    (*s_esp_zb_data_ind_handler)(&local_40);
    return;
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/platform_esp/esp-zigbee/compat/src/aps_compat.c"
                ,0x35,"esp_zb_apsde_data_indication_handler","ind != NULL");
                    /* WARNING: Bad instruction - Truncating control flow here */
  halt_baddata();
}

