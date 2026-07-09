/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ezb_zcl_ias_ace_cluster_server_init
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined4 ezb_zcl_ias_ace_cluster_server_init(undefined4 param_1)

{
  int iVar1;
  int *piVar2;
  char *__src;
  void *__dest;
  undefined4 uStack_24;
  undefined4 uStack_20;
  undefined4 uStack_1c;
  code *pcStack_18;
  code *pcStack_14;
  
  uStack_24 = 0x10501;
  uStack_20 = 0;
  uStack_1c = 0;
  pcStack_18 = ias_ace_cluster_srv_cmd_disc_handler;
  pcStack_14 = ias_ace_cluster_srv_cmd_proc_handler;
  iVar1 = zone_table_init();
  if (iVar1 == 0) {
    zone_table_restore(param_1);
    iVar1 = zcl_cluster_template_add(&uStack_24);
    if (iVar1 == 0) {
      return 0;
    }
  }
  else {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x374,
                  "ezb_zcl_ias_ace_cluster_server_init","zone_table_init(ep_id) == 0");
  }
  piVar2 = (int *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c"
                                ,0x376,"ezb_zcl_ias_ace_cluster_server_init",
                                "zcl_cluster_template_add(&template) == EZB_ZCL_STATUS_SUCCESS");
  if ((((piVar2 != (int *)0x0) && (__src != (char *)0x0)) && (*__src != -1)) &&
     (*(short *)(__src + 2) != -1)) {
    if (((*(int *)(__src + 4) != 0 || *(int *)(__src + 8) != 0) &&
        ((*(int *)(__src + 4) != -1 || (*(int *)(__src + 8) != -1)))) &&
       (iVar1 = ias_ace_zone_table_get_zone(piVar2), iVar1 == 0)) {
      for (iVar1 = 0; iVar1 < (int)(uint)*(byte *)(piVar2 + 1); iVar1 = iVar1 + 1) {
        __dest = (void *)(*piVar2 + iVar1 * 0x1e);
        if (*(short *)((int)__dest + 2) == -1) {
          memcpy(__dest,__src,0x1e);
          zone_table_store_zone(*(undefined1 *)((int)piVar2 + 5),__dest);
          return 0;
        }
      }
    }
  }
  return 2;
}

