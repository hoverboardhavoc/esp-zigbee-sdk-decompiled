/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_cli.o -> ota_upgrade_downloading_context_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t ota_upgrade_downloading_context_init(uint8_t ep_id)

{
  zcl_attr_desc_t *pzVar1;
  undefined4 *puVar2;
  
  pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,0xeff0);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
    return 5;
  }
  puVar2 = (undefined4 *)calloc(1,0x74);
  pzVar1->data_p = puVar2;
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
  pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,0);
  if (pzVar1 == (zcl_attr_desc_t *)0x0) {
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
    *puVar2 = pzVar1->data_p;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,1);
    if (pzVar1 == (zcl_attr_desc_t *)0x0) goto _L0;
    puVar2[1] = pzVar1->data_p;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,2);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    }
    puVar2[2] = pzVar1;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,3);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    }
    puVar2[3] = pzVar1;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,4);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    }
    puVar2[4] = pzVar1;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,5);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
    }
    puVar2[5] = pzVar1;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,6);
    if (pzVar1 == (zcl_attr_desc_t *)0x0) goto _L0;
    puVar2[6] = pzVar1->data_p;
    pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,7);
    if (pzVar1 != (zcl_attr_desc_t *)0x0) {
      puVar2[7] = pzVar1->data_p;
      pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,8);
      if (pzVar1 != (zcl_attr_desc_t *)0x0) {
        puVar2[8] = pzVar1->data_p;
        pzVar1 = ota_upgrade_cli_get_attr_desc(ep_id,9);
        if (pzVar1 != (zcl_attr_desc_t *)0x0) {
          pzVar1 = (zcl_attr_desc_t *)pzVar1->data_p;
        }
        puVar2[9] = pzVar1;
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

