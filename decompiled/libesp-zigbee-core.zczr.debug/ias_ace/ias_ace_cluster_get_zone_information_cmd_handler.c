/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> ias_ace.o -> ias_ace_cluster_get_zone_information_cmd_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void ias_ace_cluster_get_zone_information_cmd_handler(int param_1,int param_2)

{
  char cVar1;
  int iVar2;
  undefined4 uVar3;
  undefined2 uVar4;
  int unaff_s2;
  uint uStack_38;
  undefined4 uStack_34;
  uint uStack_2c;
  undefined4 uStack_28;
  char cStack_23;
  undefined2 auStack_22 [7];
  
  auStack_22[0] = 0;
  cStack_23 = '\0';
  uStack_2c = 0;
  uStack_28 = 0;
  if ((param_1 == 0) || (param_2 == 0)) {
    uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ias_ace.c",
                          0x169,"ias_ace_cluster_get_zone_information_cmd_handler","packet && rsp");
_L0:
    uVar4 = 0xffff;
  }
  else {
    iVar2 = af_read_le8(*(undefined4 *)(param_1 + 0x24),auStack_22,&cStack_23);
    if (iVar2 != 1) {
      iVar2 = 0x80;
      goto _L0;
    }
    if (cStack_23 == -1) {
      iVar2 = 0x87;
      goto _L0;
    }
    iVar2 = ezb_zcl_ias_ace_get_zone_table(*(undefined1 *)(param_1 + 0x15));
    cVar1 = cStack_23;
    if (iVar2 == 0) {
      iVar2 = 0x80;
      goto _L0;
    }
    unaff_s2 = ias_ace_zone_table_get_zone(cStack_23);
    uStack_38 = CONCAT31(uStack_38._1_3_,cVar1);
    iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
    if (iVar2 != 0) {
      iVar2 = 0x89;
      goto _L0;
    }
    uVar3 = *(undefined4 *)(param_2 + 0x24);
    if (unaff_s2 == 0) goto _L0;
    uVar4 = *(undefined2 *)(unaff_s2 + 2);
  }
  uStack_38 = CONCAT22(uStack_38._2_2_,uVar4);
  iVar2 = zmsg_append_bytes(uVar3,2,&uStack_38);
  if (iVar2 == 0) {
    if (unaff_s2 == 0) {
      uStack_2c = 0xffffffff;
      uStack_28 = 0xffffffff;
    }
    else {
      uStack_2c = *(uint *)(unaff_s2 + 4);
      uStack_28 = *(undefined4 *)(unaff_s2 + 8);
    }
    uStack_38 = uStack_2c;
    uStack_34 = uStack_28;
    iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),8,&uStack_38);
    if (iVar2 == 0) {
      if ((unaff_s2 == 0) || (*(byte *)(unaff_s2 + 0xd) == 0)) {
        uStack_38 = uStack_38 & 0xffffff00;
        iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
        if (iVar2 != 0) {
          iVar2 = 0x89;
          goto _L0;
        }
      }
      else {
        iVar2 = zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),*(byte *)(unaff_s2 + 0xd) + 1,
                                  unaff_s2 + 0xd);
        if (iVar2 != 0) {
          iVar2 = 0x89;
          goto _L0;
        }
      }
      iVar2 = zcl_packet_setup_response(param_2,param_1,2);
      if (iVar2 == 0) {
        return;
      }
    }
    else {
      iVar2 = 0x89;
    }
  }
  else {
    iVar2 = 0x89;
  }
_L0:
  zcl_packet_setup_default_response(param_2,param_1,iVar2);
  return;
}

