/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_bypassed_zone_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_bypassed_zone_list_cmd_handler(int param_1,int param_2)

{
  int unaff_s0;
  int *unaff_s1;
  int iVar1;
  char *pcVar2;
  char unaff_s3;
  char acStack_21 [9];
  
  if ((param_1 == 0) || (param_2 == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x1ae,
                  "ias_ace_cluster_get_bypassed_zone_list_cmd_handler","packet && rsp");
    goto _L0;
  }
  unaff_s1 = (int *)ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
  if (unaff_s1 == (int *)0x0) {
    iVar1 = 0x8b;
  }
  else {
    acStack_21[0] = '\0';
    iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,acStack_21);
    if (iVar1 == 0) {
      acStack_21[0] = '\0';
      for (unaff_s0 = 0; unaff_s0 < (int)(uint)*(byte *)(unaff_s1 + 1); unaff_s0 = unaff_s0 + 1) {
        pcVar2 = (char *)(unaff_s0 * 0x1e + *unaff_s1);
        unaff_s3 = acStack_21[0];
        if ((pcVar2[0xc] & 1U) != 0) {
          unaff_s3 = acStack_21[0] + '\x01';
          acStack_21[0] = *pcVar2;
          iVar1 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,acStack_21);
          if (iVar1 != 0) {
            iVar1 = 0x89;
            goto _L0;
          }
        }
_L0:
        acStack_21[0] = unaff_s3;
      }
      zmsg_write_bytes(*(undefined4 *)(param_2 + 0x24),0,1,acStack_21);
      iVar1 = zcl_packet_setup_response(param_2,param_1,6);
      if (iVar1 == 0) {
        return;
      }
    }
    else {
      iVar1 = 0x89;
    }
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar1);
  return;
}

