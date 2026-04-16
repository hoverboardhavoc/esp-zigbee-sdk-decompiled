/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_bypassed_zone_list_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ias_ace_cluster_get_bypassed_zone_list_cmd_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  int unaff_s0;
  int *unaff_s1;
  int iVar1;
  char *pcVar2;
  char unaff_s3;
  char acStack_21 [9];
  
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//build/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",0x1ae,
                  "ias_ace_cluster_get_bypassed_zone_list_cmd_handler","packet && rsp");
    goto _L0;
  }
  unaff_s1 = (int *)ezb_zcl_ias_ace_get_zone_table((packet->header).dst_ep);
  if (unaff_s1 == (int *)0x0) {
    iVar1 = 0x8b;
  }
  else {
    acStack_21[0] = '\0';
    iVar1 = zmsg_append_bytes(rsp->payload,1,acStack_21);
    if (iVar1 == 0) {
      acStack_21[0] = '\0';
      for (unaff_s0 = 0; unaff_s0 < (int)(uint)*(byte *)(unaff_s1 + 1); unaff_s0 = unaff_s0 + 1) {
        pcVar2 = (char *)(unaff_s0 * 0x1e + *unaff_s1);
        unaff_s3 = acStack_21[0];
        if ((pcVar2[0xc] & 1U) != 0) {
          unaff_s3 = acStack_21[0] + '\x01';
          acStack_21[0] = *pcVar2;
          iVar1 = zmsg_append_bytes(rsp->payload,1,acStack_21);
          if (iVar1 != 0) {
            iVar1 = 0x89;
            goto _L0;
          }
        }
_L0:
        acStack_21[0] = unaff_s3;
      }
      zmsg_write_bytes(rsp->payload,0,1,acStack_21);
      iVar1 = zcl_packet_setup_response(rsp,packet,6);
      if (iVar1 == 0) goto _L0;
    }
    else {
      iVar1 = 0x89;
    }
  }
_L0:
  iVar1 = zcl_packet_setup_default_response(rsp,packet,iVar1);
_L0:
  return (ezb_zcl_status_t)iVar1;
}

