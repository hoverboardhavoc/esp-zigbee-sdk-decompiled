/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_read_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_read_attr_handler(int param_1,int param_2)

{
  uint uVar1;
  short *psVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  undefined4 uVar6;
  int unaff_s5;
  undefined2 uVar7;
  undefined4 uStack_3c;
  ushort uStack_36;
  undefined2 auStack_34 [8];
  
  auStack_34[0] = 0;
  if ((((param_1 == 0) || (unaff_s5 = *(int *)(param_1 + 0x24), unaff_s5 == 0)) || (param_2 == 0))
     || (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x72,
                  "zcl_general_read_attr_handler","packet && packet->payload && rsp && rsp->payload"
                 );
  }
  else if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
    uVar7 = *(undefined2 *)(param_1 + 0x1c);
    goto _L0;
  }
  uVar7 = 0;
_L0:
  uVar1 = zmsg_get_length(unaff_s5);
  uStack_36 = 0;
  if ((uVar1 & 1) == 0) {
_L0:
    if (uStack_36 < uVar1) {
      auStack_34[0] = 0;
      af_read_le16(unaff_s5,&uStack_36,auStack_34);
      if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
        uVar6 = 1;
      }
      else {
        uVar6 = 2;
      }
      psVar2 = (short *)zcl_get_attr_desc(*(undefined1 *)(param_1 + 0x15),
                                          *(undefined2 *)(param_1 + 0x16),uVar6,auStack_34[0],uVar7)
      ;
      iVar3 = check_read_attr_filed();
      uVar4 = zcl_packet_max_available_space
                        (*(undefined2 *)(param_1 + 0x16),0,*(byte *)(param_1 + 0x1a) >> 2 & 1);
      uVar5 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
      if (uVar4 <= uVar5) {
        uVar6 = 0x89;
        goto _L0;
      }
      uStack_3c = CONCAT22(uStack_3c._2_2_,auStack_34[0]);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_3c);
      uStack_3c = CONCAT31(uStack_3c._1_3_,(char)iVar3);
      zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_3c);
      if (iVar3 == 0) {
        uStack_3c = CONCAT31(uStack_3c._1_3_,(char)psVar2[1]);
        zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_3c);
        if ((*(short *)(param_1 + 0x16) == 10) && ((*(byte *)(param_1 + 0x1a) & 8) == 0)) {
          if (((ushort)(*psVar2 - 6U) < 2) || (*psVar2 == 0)) {
            uStack_3c = 0;
            iVar3 = zcl_time_cluster_read_time(*(undefined1 *)(param_1 + 0x15),*psVar2,&uStack_3c);
            if (iVar3 != 0) {
              uVar6 = 0x8b;
              goto _L0;
            }
            zcl_packet_append_variable_attr_value
                      (*(undefined4 *)(param_2 + 0x24),(char)psVar2[1],&uStack_3c);
            goto _L0;
          }
        }
        zcl_packet_append_variable_attr_value
                  (*(undefined4 *)(param_2 + 0x24),(char)psVar2[1],*(undefined4 *)(psVar2 + 4));
      }
      goto _L0;
    }
    zcl_packet_setup_response(param_2,param_1,1);
  }
  else {
    uVar6 = 0x80;
_L0:
    zcl_packet_setup_default_response(param_2,param_1,uVar6);
  }
  return;
}

