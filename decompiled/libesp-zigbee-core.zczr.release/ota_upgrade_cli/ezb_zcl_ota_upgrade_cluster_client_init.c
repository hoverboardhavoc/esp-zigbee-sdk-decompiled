/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_cli.o -> ezb_zcl_ota_upgrade_cluster_client_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ezb_zcl_ota_upgrade_cluster_client_init(undefined4 param_1)

{
  undefined4 *unaff_s0;
  int iVar1;
  undefined1 auStack_24 [20];
  
  memcpy(auStack_24,&_LANCHOR0,0x14);
  iVar1 = ota_upgrade_cli_get_attr_desc_part_0(param_1);
  if (iVar1 != 0) {
    unaff_s0 = (undefined4 *)calloc(1,0x74);
    *(undefined4 **)(iVar1 + 8) = unaff_s0;
    if (unaff_s0 != (undefined4 *)0x0) {
      unaff_s0[0xc] = 0x330;
      *(undefined1 *)(unaff_s0 + 0xe) = 0;
      unaff_s0[10] = 0;
      unaff_s0[0xb] = 0;
      unaff_s0[0xd] = 5000;
      milli_timer_init(unaff_s0 + 0xf,ota_upgrade_download_retry,unaff_s0);
      iVar1 = ota_upgrade_cli_get_attr_desc(param_1,0);
      if (iVar1 != 0) goto _L0;
    }
  }
  do {
    do {
      do {
        do {
          do {
            iVar1 = __assert_func(0,0,0,0);
_L0:
            *unaff_s0 = *(undefined4 *)(iVar1 + 8);
            iVar1 = ota_upgrade_cli_get_attr_desc(param_1,1);
          } while (iVar1 == 0);
          unaff_s0[1] = *(undefined4 *)(iVar1 + 8);
          iVar1 = ota_upgrade_cli_get_attr_desc(param_1,2);
          if (iVar1 != 0) {
            iVar1 = *(int *)(iVar1 + 8);
          }
          unaff_s0[2] = iVar1;
          iVar1 = ota_upgrade_cli_get_attr_desc(param_1,3);
          if (iVar1 != 0) {
            iVar1 = *(int *)(iVar1 + 8);
          }
          unaff_s0[3] = iVar1;
          iVar1 = ota_upgrade_cli_get_attr_desc(param_1,4);
          if (iVar1 != 0) {
            iVar1 = *(int *)(iVar1 + 8);
          }
          unaff_s0[4] = iVar1;
          iVar1 = ota_upgrade_cli_get_attr_desc(param_1,5);
          if (iVar1 != 0) {
            iVar1 = *(int *)(iVar1 + 8);
          }
          unaff_s0[5] = iVar1;
          iVar1 = ota_upgrade_cli_get_attr_desc(param_1,6);
        } while (iVar1 == 0);
        unaff_s0[6] = *(undefined4 *)(iVar1 + 8);
        iVar1 = ota_upgrade_cli_get_attr_desc(param_1,7);
      } while (iVar1 == 0);
      unaff_s0[7] = *(undefined4 *)(iVar1 + 8);
      iVar1 = ota_upgrade_cli_get_attr_desc(param_1,8);
    } while (iVar1 == 0);
    unaff_s0[8] = *(undefined4 *)(iVar1 + 8);
    iVar1 = ota_upgrade_cli_get_attr_desc(param_1,9);
    if (iVar1 != 0) {
      iVar1 = *(int *)(iVar1 + 8);
    }
    unaff_s0[9] = iVar1;
    iVar1 = zcl_cluster_template_add(auStack_24);
  } while (iVar1 != 0);
  return;
}

