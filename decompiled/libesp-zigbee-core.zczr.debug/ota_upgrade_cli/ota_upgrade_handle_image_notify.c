/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_image_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_handle_image_notify(int param_1,uint param_2,byte *param_3,uint param_4)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  
  if ((param_1 == 0) || (param_3 == (byte *)0x0)) {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                            ,0x19b,"ota_upgrade_handle_image_notify","context && payload");
_L0:
    if (param_4 != 3) {
      return 0x96;
    }
    if (*(int **)(param_1 + 8) == (int *)0x0) {
      iVar3 = -1;
    }
    else {
      iVar3 = **(int **)(param_1 + 8);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) {
      iVar2 = -1;
    }
    else {
      iVar2 = **(int **)(param_1 + 0x10);
    }
    if (*(int *)(param_3 + 8) == iVar3) {
      return 0x96;
    }
    if (*(int *)(param_3 + 8) == iVar2) {
      return 0x96;
    }
_L0:
    if ((*(short *)(param_3 + 4) != **(short **)(param_1 + 0x20)) && (*(short *)(param_3 + 4) != -1)
       ) {
      return 0x96;
    }
  }
  else {
    if (param_2 < 0xfff8) {
      uVar1 = nwk_get_short_address();
      if (uVar1 != param_2) {
        return 0x96;
      }
      goto _L0;
    }
    param_4 = (uint)*param_3;
    if (param_4 == 2) goto _L0;
    if (2 < param_4) goto _L0;
    if (param_4 == 0) goto _L0;
    if (param_4 != 1) {
      return 0x96;
    }
  }
  if ((*(short *)(param_3 + 2) != **(short **)(param_1 + 0x1c)) && (*(short *)(param_3 + 2) != -1))
  {
    return 0x96;
  }
_L0:
  uVar1 = random_noncrypto_get_u32();
  if ((uint)param_3[1] < uVar1 % 100) {
    return 0xfe;
  }
  return 0;
}

