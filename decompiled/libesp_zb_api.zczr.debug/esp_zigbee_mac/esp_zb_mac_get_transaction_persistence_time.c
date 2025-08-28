/*
 * Last changed at upstream commit 88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * https://github.com/espressif/esp-zigbee-sdk/commit/88dfcd2f3748e37cbfac85eea52d0fdfbe99049b
 * Upstream date: 2025-08-28 11:19:03 +0000
 * Upstream subject: esp-zigbee-sdk: (0166821f)
 * Source: libesp_zb_api.zczr.debug -> esp_zigbee_mac.o -> esp_zb_mac_get_transaction_persistence_time
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int esp_zb_mac_get_transaction_persistence_time(void)

{
  int iVar1;
  undefined1 *puVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = zb_buf_get_out_func();
  if (iVar1 == 0) {
    uVar4 = esp_log_timestamp();
    esp_log_write(1,0x10000,&_L0,uVar4,0x10000,"esp_zb_mac_get_transaction_persistence_time",0x4e);
    iVar1 = 0x101;
  }
  else {
    puVar2 = (undefined1 *)zb_buf_begin_func();
    *puVar2 = 0x55;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    zb_mlme_get_request(iVar1);
    iVar3 = zb_buf_begin_func(iVar1);
    if (*(char *)(iVar3 + 2) == '\0') {
      if (*(char *)(iVar3 + 3) == '\x02') {
        iVar1 = zb_buf_begin_func(iVar1);
        iVar1 = (uint)*(ushort *)(iVar1 + 4) * 0x3c00;
      }
      else {
        iVar1 = -1;
      }
    }
    else {
      iVar1 = -1;
    }
  }
  return iVar1;
}

