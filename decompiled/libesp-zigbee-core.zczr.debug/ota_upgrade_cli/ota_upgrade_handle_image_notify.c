/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_handle_image_notify
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_handle_image_notify(int param_1,uint param_2,char *param_3)

{
  char cVar1;
  uint uVar2;
  int iVar3;
  int iVar4;
  
  if ((param_1 == 0) || (param_3 == (char *)0x0)) {
    param_1 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                            ,0x1a9,"ota_upgrade_handle_image_notify","context && payload");
_L0:
    if (*(int **)(param_1 + 8) == (int *)0x0) {
      iVar4 = -1;
    }
    else {
      iVar4 = **(int **)(param_1 + 8);
    }
    if (*(int **)(param_1 + 0x10) == (int *)0x0) {
      iVar3 = -1;
    }
    else {
      iVar3 = **(int **)(param_1 + 0x10);
    }
    if (*(int *)(param_3 + 8) == iVar4) {
      return 0x96;
    }
    if (*(int *)(param_3 + 8) == iVar3) {
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
      uVar2 = nwk_get_short_address();
      if (uVar2 != param_2) {
        return 0x96;
      }
      goto _L0;
    }
    cVar1 = *param_3;
    if (cVar1 == '\x02') goto _L0;
    if (cVar1 == '\x03') goto _L0;
    if (cVar1 != '\x01') {
      return 0x96;
    }
  }
  if ((*(short *)(param_3 + 2) != **(short **)(param_1 + 0x1c)) && (*(short *)(param_3 + 2) != -1))
  {
    return 0x96;
  }
_L0:
  uVar2 = random_noncrypto_get_u32();
  if ((uint)(byte)param_3[1] < uVar2 % 100) {
    return 0xfe;
  }
  return 0;
}

