/*
 * Last changed at upstream commit 232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * https://github.com/espressif/esp-zigbee-sdk/commit/232ecc4094b2fa86cc70f7e95820b15daf5d0bff
 * Upstream date: 2025-07-25 14:23:12 +0800
 * Upstream subject: esp-zigbee-sdk: (5de57b2b)
 * Source: libesp_zb_api.zczr -> esp_zigbee_mac.o -> esp_zb_mac_get_transaction_persistence_time
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
  int iVar4;
  
  iVar1 = zb_buf_get_out_func();
  iVar4 = 0x101;
  if (iVar1 != 0) {
    puVar2 = (undefined1 *)zb_buf_begin_func();
    *puVar2 = 0x55;
    puVar2[1] = 0;
    puVar2[2] = 0;
    puVar2[3] = 0;
    puVar2[4] = 0;
    puVar2[5] = 0;
    zb_mlme_get_request(iVar1);
    iVar3 = zb_buf_begin_func(iVar1);
    iVar4 = -1;
    if ((*(char *)(iVar3 + 2) == '\0') && (*(char *)(iVar3 + 3) == '\x02')) {
      iVar1 = zb_buf_begin_func(iVar1);
      iVar4 = (uint)*(ushort *)(iVar1 + 4) * 0x3c00;
    }
  }
  return iVar4;
}

