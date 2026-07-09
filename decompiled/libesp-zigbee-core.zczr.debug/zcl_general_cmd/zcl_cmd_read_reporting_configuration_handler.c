/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_cmd_read_reporting_configuration_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_cmd_read_reporting_configuration_handler(int param_1,int param_2)

{
  char cVar1;
  undefined1 *puVar2;
  undefined2 *puVar3;
  uint uVar4;
  undefined2 *puVar5;
  int iVar6;
  int iVar7;
  undefined4 uVar8;
  int unaff_s2;
  undefined2 uVar9;
  undefined2 uStack_38;
  ushort uStack_36;
  undefined4 uStack_34;
  
  uStack_34 = 0;
  if ((((param_1 == 0) || (unaff_s2 = *(int *)(param_1 + 0x24), unaff_s2 == 0)) || (param_2 == 0))
     || (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x2d6,
                  "zcl_cmd_read_reporting_configuration_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
    uVar9 = *(undefined2 *)(param_1 + 0x1c);
    goto _L0;
  }
  uVar9 = 0;
_L0:
  puVar2 = (undefined1 *)af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
  if (puVar2 == (undefined1 *)0x0) {
    uVar8 = 0x81;
  }
  else {
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
      uVar8 = 1;
    }
    else {
      uVar8 = 2;
    }
    puVar3 = (undefined2 *)
             af_endpoint_get_cluster_desc(puVar2,*(undefined2 *)(param_1 + 0x16),uVar8);
    if (puVar3 == (undefined2 *)0x0) {
      uVar8 = 0xc3;
    }
    else {
      uVar4 = zmsg_get_length(unaff_s2);
      uStack_36 = 0;
      while( true ) {
        if (uVar4 <= uStack_36) {
          zcl_packet_setup_response(param_2,param_1,9);
          return;
        }
        af_read_le8(unaff_s2,&uStack_36,&uStack_34);
        af_read_le16(unaff_s2,&uStack_36,(int)&uStack_34 + 2);
        if (uVar4 < uStack_36) break;
        puVar5 = (undefined2 *)zcl_cluster_get_attr_desc(puVar3,uStack_34 >> 0x10,uVar9);
        iVar6 = check_read_reporting_configuration_field(&uStack_34,puVar5);
        if (iVar6 == 0) {
          iVar6 = zcl_reporting_info_find
                            (*puVar2,*puVar3,*(undefined1 *)(puVar3 + 1),*puVar5,puVar5[2]);
          cVar1 = '\0';
          if (iVar6 == 0) {
            cVar1 = -0x75;
          }
          uStack_38._0_1_ = cVar1;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,(char)uStack_34);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
          uStack_38 = uStack_34._2_2_;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
          if (cVar1 == '\0') {
            if ((char)uStack_34 == '\0') {
              uStack_38 = CONCAT11(uStack_38._1_1_,*(undefined1 *)(puVar5 + 1));
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
              uStack_38 = *(undefined2 *)(iVar6 + 0x10);
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
              uStack_38 = *(undefined2 *)(iVar6 + 0x12);
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
              iVar7 = zcl_attr_type_is_analog(*(undefined1 *)(puVar5 + 1));
              if (iVar7 != 0) {
                zcl_packet_append_variable_attr_value
                          (*(undefined4 *)(param_2 + 0x24),*(undefined1 *)(puVar5 + 1),iVar6 + 0x18)
                ;
              }
            }
            else {
              uStack_38 = *(undefined2 *)(iVar6 + 0x10);
              zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
            }
          }
        }
        else {
          uStack_38._0_1_ = (char)iVar6;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
          uStack_38 = CONCAT11(uStack_38._1_1_,(char)uStack_34);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_38);
          uStack_38 = uStack_34._2_2_;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_38);
        }
      }
      uVar8 = 0x80;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar8);
  return;
}

