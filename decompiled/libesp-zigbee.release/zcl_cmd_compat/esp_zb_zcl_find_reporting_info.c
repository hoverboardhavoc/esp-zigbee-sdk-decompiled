/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee.release -> zcl_cmd_compat.o -> esp_zb_zcl_find_reporting_info
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */

undefined2 * esp_zb_zcl_find_reporting_info(undefined1 *param_1)

{
  undefined2 *puVar1;
  undefined2 *puVar2;
  
  puVar2 = (undefined2 *)
           ezb_zcl_reporting_info_find
                     (*param_1,*(undefined2 *)(param_1 + 2),param_1[4],*(undefined2 *)(param_1 + 8),
                      *(undefined2 *)(param_1 + 6));
  puVar1 = puVar2;
  if (puVar2 != (undefined2 *)0x0) {
    _s_esp_zb_find_reporting_info_out_0 = CONCAT22(puVar2[2],*puVar2);
    _DAT_00013edc = (ushort)*(byte *)(puVar2 + 4);
    DAT_00013ede = puVar2[3];
    DAT_00013f16 = puVar2[0x18];
    DAT_00013ee0 = (undefined1)((uint)*(undefined4 *)(puVar2 + 4) >> 8);
    memcpy(&s_esp_zb_find_reporting_info_out_0,puVar2 + 8,0x20);
    puVar1 = (undefined2 *)&s_esp_zb_find_reporting_info_out_0;
    DAT_00013f18 = puVar2;
  }
  return puVar1;
}

