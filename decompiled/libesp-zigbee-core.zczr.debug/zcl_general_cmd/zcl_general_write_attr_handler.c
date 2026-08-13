/*
 * Last changed at upstream commit ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * https://github.com/espressif/esp-zigbee-sdk/commit/ecca8a8cee0ba565a3b8dbe9d288517b724f31a9
 * Upstream date: 2026-08-13 06:13:24 +0000
 * Upstream subject: change: update esp-zigbee-lib (e4bad48f)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_general_cmd.o -> zcl_general_write_attr_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zcl_general_write_attr_handler(int param_1,int param_2)

{
  int iVar1;
  uint uVar2;
  size_t __size;
  int iVar3;
  undefined4 uVar4;
  undefined4 uVar5;
  int unaff_s2;
  undefined2 uVar6;
  ushort uStack_3c;
  ushort local_3a;
  undefined4 uStack_38;
  void *pvStack_34;
  
  uStack_38 = 0;
  pvStack_34 = (void *)0x0;
  if ((((param_1 == 0) || (unaff_s2 = *(int *)(param_1 + 0x24), unaff_s2 == 0)) || (param_2 == 0))
     || (*(int *)(param_2 + 0x24) == 0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_general_cmd.c",0x11a,
                  "zcl_general_write_attr_handler",
                  "packet && packet->payload && rsp && rsp->payload");
  }
  else if ((*(byte *)(param_1 + 0x1a) & 4) != 0) {
    uVar6 = *(undefined2 *)(param_1 + 0x1c);
    goto _L0;
  }
  uVar6 = 0;
_L0:
  iVar1 = af_get_ep_desc(*(undefined1 *)(param_1 + 0x15));
  if (iVar1 == 0) {
    uVar4 = 0x81;
  }
  else {
    if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
      uVar4 = 1;
    }
    else {
      uVar4 = 2;
    }
    iVar1 = af_endpoint_get_cluster_desc(*(undefined2 *)(param_1 + 0x16),uVar4);
    if (iVar1 == 0) {
      uVar4 = 0xc3;
    }
    else {
      uVar2 = zmsg_get_length(unaff_s2);
      local_3a = 0;
      while (local_3a < uVar2) {
        uStack_38 = 0;
        pvStack_34 = (void *)0x0;
        af_read_le16(unaff_s2,&local_3a,&uStack_38);
        af_read_le8(unaff_s2,&local_3a,(int)&uStack_38 + 2);
        __size = zcl_packet_read_variable_attr_size
                           (*(undefined4 *)(param_1 + 0x24),local_3a,uStack_38 >> 0x10 & 0xff);
        pvStack_34 = calloc(1,__size);
        zcl_packet_read_variable_attr_value(unaff_s2,&local_3a,uStack_38 >> 0x10 & 0xff,pvStack_34);
        uVar4 = zcl_cluster_get_attr_desc(iVar1,uStack_38 & 0xffff,uVar6);
        iVar3 = check_write_attr_filed(&uStack_38,uVar4);
        if (iVar3 == 0) {
          if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
            uVar5 = 1;
          }
          else {
            uVar5 = 2;
          }
          iVar3 = zcl_set_attr_value(*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16)
                                     ,uVar5,uStack_38 & 0xffff,uVar6,pvStack_34,0);
          if (iVar3 != 0) goto _L0;
          if ((*(short *)(param_1 + 0x16) == 0x500) && ((*(byte *)(param_1 + 0x1a) & 8) == 0)) {
            ias_zone_cluster_srv_set_attr_val_post_proc(param_1,uStack_38 & 0xffff,pvStack_34);
          }
          if ((*(byte *)(param_1 + 0x1a) & 8) == 0) {
            uVar5 = 1;
          }
          else {
            uVar5 = 2;
          }
          zcl_message_notify_attr_value
                    (*(undefined1 *)(param_1 + 0x15),*(undefined2 *)(param_1 + 0x16),uVar5,uVar4);
        }
        else {
_L0:
          uStack_3c = CONCAT11(uStack_3c._1_1_,(char)iVar3);
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_3c);
          uStack_3c = (ushort)uStack_38;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),2,&uStack_3c);
        }
        mm_free(pvStack_34);
      }
      if (local_3a == uVar2) {
        iVar1 = zmsg_get_length(*(undefined4 *)(param_2 + 0x24));
        if (iVar1 == 0) {
          uStack_3c = uStack_3c & 0xff00;
          zmsg_append_bytes(*(undefined4 *)(param_2 + 0x24),1,&uStack_3c);
        }
        zcl_packet_setup_response(param_2,param_1,4);
        return;
      }
      uVar4 = 0x80;
    }
  }
  zcl_packet_setup_default_response(param_2,param_1,uVar4);
  return;
}

