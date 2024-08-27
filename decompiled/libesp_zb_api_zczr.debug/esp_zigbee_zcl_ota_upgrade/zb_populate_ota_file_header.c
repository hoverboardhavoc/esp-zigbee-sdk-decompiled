/*
 * Last changed at upstream commit eec5098a388a0960da2662a0145e34c21f0838a0
 * https://github.com/espressif/esp-zigbee-sdk/commit/eec5098a388a0960da2662a0145e34c21f0838a0
 * Upstream date: 2024-08-27 08:46:30 +0000
 * Upstream subject: esp-zigbee-lib:(6bd34178)
 * Source: libesp_zb_api_zczr.debug -> esp_zigbee_zcl_ota_upgrade.o -> zb_populate_ota_file_header
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 zb_populate_ota_file_header(undefined2 *param_1,int param_2)

{
  ushort uVar1;
  undefined1 *puVar2;
  undefined4 uVar3;
  
  if (param_1 != (undefined2 *)0x0) {
    if (param_2 == 0) {
      uVar3 = 0x102;
    }
    else {
      *(undefined4 *)(param_1 + 2) = *(undefined4 *)(param_2 + 0xe);
      *(uint *)(param_1 + 4) = *(int *)(param_2 + 0x34) - (uint)*(ushort *)(param_2 + 6);
      param_1[1] = *(undefined2 *)(param_2 + 0xc);
      uVar1 = *(ushort *)(param_2 + 8);
      param_1[6] = uVar1;
      *param_1 = *(undefined2 *)(param_2 + 10);
      *(undefined1 *)(param_1 + 7) = 0;
      *(undefined1 *)((int)param_1 + 0xf) = 0;
      *(undefined1 *)(param_1 + 8) = 0;
      *(undefined1 *)((int)param_1 + 0x11) = 0;
      *(undefined1 *)(param_1 + 9) = 0;
      *(undefined1 *)((int)param_1 + 0x13) = 0;
      *(undefined1 *)(param_1 + 10) = 0;
      *(undefined1 *)((int)param_1 + 0x15) = 0;
      *(undefined1 *)(param_1 + 0xb) = 0;
      *(undefined1 *)((int)param_1 + 0x17) = 0;
      *(undefined1 *)(param_1 + 0xc) = 0;
      *(undefined1 *)((int)param_1 + 0x19) = 0;
      *(undefined1 *)(param_1 + 0xd) = 0;
      *(undefined1 *)((int)param_1 + 0x1b) = 0;
      puVar2 = (undefined1 *)(param_2 + 0x38);
      if ((uVar1 & 1) != 0) {
        *(undefined1 *)(param_1 + 7) = *(undefined1 *)(param_2 + 0x38);
        puVar2 = (undefined1 *)(param_2 + 0x39);
      }
      if ((uVar1 & 2) != 0) {
        zb_memcpy8((int)param_1 + 0xf,puVar2);
        puVar2 = puVar2 + 8;
      }
      if ((param_1[6] & 4) == 0) {
        uVar3 = 0;
      }
      else {
        *(undefined1 *)(param_1 + 0xc) = *puVar2;
        *(undefined1 *)((int)param_1 + 0x19) = puVar2[1];
        *(undefined1 *)(param_1 + 0xd) = puVar2[2];
        *(undefined1 *)((int)param_1 + 0x1b) = puVar2[3];
        uVar3 = 0;
      }
    }
    return uVar3;
  }
  return 0x102;
}

