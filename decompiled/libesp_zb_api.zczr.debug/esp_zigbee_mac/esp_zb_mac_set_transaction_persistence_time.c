/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_mac.o -> esp_zb_mac_set_transaction_persistence_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 esp_zb_mac_set_transaction_persistence_time(uint param_1)

{
  int iVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  undefined1 uStack_12;
  undefined1 uStack_11;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar3 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_LC1,uVar3,0x10000,"esp_zb_mac_set_transaction_persistence_time",0x38);
    uVar3 = 0x101;
  }
  else {
    puVar2 = (undefined1 *)zb_buf_begin_func();
    if (param_1 < 0x3c000000) {
      *puVar2 = 0x55;
      puVar2[1] = 0;
      puVar2[2] = 2;
      puVar2[3] = 0;
      puVar2[4] = 0;
      puVar2[5] = 0;
      puVar2[6] = 0;
      uStack_12 = (undefined1)(param_1 / 0x3c00);
      puVar2[0xb] = uStack_12;
      uStack_11 = (undefined1)(param_1 / 0x3c00 >> 8);
      puVar2[0xc] = uStack_11;
      zb_mlme_set_request(iVar1);
      uVar3 = 0;
    }
    else {
      uVar3 = esp_log_timestamp();
      esp_log_write(1,0x10000,&_LC2,uVar3,0x10000,"esp_zb_mac_set_transaction_persistence_time",0x3b
                    ,param_1);
      uVar3 = 0x102;
    }
  }
  return uVar3;
}

