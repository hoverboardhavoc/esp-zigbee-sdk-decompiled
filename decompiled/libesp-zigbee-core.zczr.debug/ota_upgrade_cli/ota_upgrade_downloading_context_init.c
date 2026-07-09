/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_downloading_context_init(undefined4 param_1)

{
  int iVar1;
  undefined4 *puVar2;
  
  iVar1 = ota_upgrade_cli_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    return 5;
  }
  puVar2 = (undefined4 *)calloc(1,0x74);
  *(undefined4 **)(iVar1 + 8) = puVar2;
  if (puVar2 == (undefined4 *)0x0) {
    return 1;
  }
  puVar2[10] = 0;
  puVar2[0xb] = 0;
  *(undefined2 *)((int)puVar2 + 0x32) = 0;
  *(undefined1 *)(puVar2 + 0xc) = 0x30;
  *(undefined1 *)((int)puVar2 + 0x31) = 3;
  puVar2[0xd] = 5000;
  *(undefined1 *)(puVar2 + 0xe) = 0;
  milli_timer_init(puVar2 + 0xf,ota_upgrade_download_retry,puVar2);
  iVar1 = ota_upgrade_cli_get_attr_desc(param_1,0);
  if (iVar1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xa9,"ota_upgrade_downloading_context_init","attr_desc");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xad,"ota_upgrade_downloading_context_init","attr_desc");
_L0:
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0xb8,"ota_upgrade_downloading_context_init","attr_desc");
  }
  else {
    *puVar2 = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,1);
    if (iVar1 == 0) goto _L0;
    puVar2[1] = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,2);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar2[2] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,3);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar2[3] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,4);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar2[4] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,5);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar2[5] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,6);
    if (iVar1 == 0) goto _L0;
    puVar2[6] = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,7);
    if (iVar1 != 0) {
      puVar2[7] = *(undefined4 *)(iVar1 + 8);
      iVar1 = ota_upgrade_cli_get_attr_desc(param_1,8);
      if (iVar1 != 0) {
        puVar2[8] = *(undefined4 *)(iVar1 + 8);
        iVar1 = ota_upgrade_cli_get_attr_desc(param_1,9);
        if (iVar1 != 0) {
          iVar1 = *(int *)(iVar1 + 8);
        }
        puVar2[9] = iVar1;
        return 0;
      }
      goto _L0;
    }
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0xbb,
                "ota_upgrade_downloading_context_init","attr_desc");
_L0:
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",0xbe,
                "ota_upgrade_downloading_context_init","attr_desc");
  return 5;
}

