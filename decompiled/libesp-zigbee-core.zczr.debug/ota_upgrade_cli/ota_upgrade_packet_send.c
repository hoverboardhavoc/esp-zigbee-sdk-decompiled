/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_packet_send
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ota_upgrade_packet_send(int param_1)

{
  int iVar1;
  undefined4 uVar2;
  undefined4 *puVar3;
  
  if (param_1 == 0) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c",
                  0x15c,"ota_upgrade_packet_send","packet");
  }
  else {
    iVar1 = ota_upgrade_downloading_context_get(*(undefined1 *)(param_1 + 0x14));
    if (iVar1 != 0) {
      zcl_packet_clone(iVar1 + 0x4c,param_1);
      zcl_packet_send(param_1,0);
      milli_timer_stop(iVar1 + 0x3c);
      uVar2 = milli_timer_start(iVar1 + 0x3c,*(undefined4 *)(iVar1 + 0x34));
      return uVar2;
    }
  }
  uVar2 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_cli.c"
                        ,0x15f,"ota_upgrade_packet_send","context");
  iVar1 = ota_upgrade_cli_get_attr_desc(0xeff0);
  if (iVar1 == 0) {
    return 5;
  }
  puVar3 = (undefined4 *)calloc(1,0x74);
  *(undefined4 **)(iVar1 + 8) = puVar3;
  if (puVar3 == (undefined4 *)0x0) {
    return 1;
  }
  puVar3[10] = 0;
  puVar3[0xb] = 0;
  *(undefined2 *)((int)puVar3 + 0x32) = 0;
  *(undefined1 *)(puVar3 + 0xc) = 0x30;
  *(undefined1 *)((int)puVar3 + 0x31) = 3;
  puVar3[0xd] = 5000;
  *(undefined1 *)(puVar3 + 0xe) = 0;
  milli_timer_init(puVar3 + 0xf,ota_upgrade_download_retry,puVar3);
  iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,0);
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
    *puVar3 = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,1);
    if (iVar1 == 0) goto _L0;
    puVar3[1] = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,2);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar3[2] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,3);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar3[3] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,4);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar3[4] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,5);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    puVar3[5] = iVar1;
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,6);
    if (iVar1 == 0) goto _L0;
    puVar3[6] = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,7);
    if (iVar1 != 0) {
      puVar3[7] = *(undefined4 *)(iVar1 + 8);
      iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,8);
      if (iVar1 != 0) {
        puVar3[8] = *(undefined4 *)(iVar1 + 8);
        iVar1 = ota_upgrade_cli_get_attr_desc(uVar2,9);
        if (iVar1 != 0) {
          iVar1 = *(int *)(iVar1 + 8);
        }
        puVar3[9] = iVar1;
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

