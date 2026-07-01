/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_write_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

void zcl_packet_write_variable_attr_value
               (zcl_packet_payload_t *payload,uint16_t offset,uint8_t attr_type,void *value)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  uint uVar4;
  zcl_packet_t *packet;
  undefined2 in_register_0000202e;
  undefined4 *extraout_a1;
  undefined3 in_register_00002031;
  ezb_addr_mode_t aeStack_60 [2];
  undefined2 uStack_5e;
  undefined2 uStack_5c;
  ezb_shortaddr_t eStack_5a;
  ezb_shortaddr_t eStack_58;
  undefined2 uStack_56;
  undefined2 uStack_54;
  uint16_t uStack_52;
  uint16_t uStack_50;
  undefined1 uStack_4e;
  zmsg_t *pzStack_4c;
  undefined4 uStack_48;
  undefined4 uStack_44;
  void *pvStack_3c;
  undefined4 uStack_38;
  code *pcStack_34;
  undefined4 local_30;
  uint8_t buf [16];
  
  uVar3 = CONCAT31(in_register_00002031,attr_type);
  local_30 = 0;
  buf[0] = '\0';
  buf[1] = '\0';
  buf[2] = '\0';
  buf[3] = '\0';
  buf[4] = '\0';
  buf[5] = '\0';
  buf[6] = '\0';
  buf[7] = '\0';
  buf[8] = '\0';
  buf[9] = '\0';
  buf[10] = '\0';
  buf[0xb] = '\0';
  iVar2 = zcl_attr_type_is_composite(uVar3);
  if (iVar2 == 0) {
    uVar4 = zcl_get_attr_value_size(uVar3,0);
    if (0x10 < uVar4) {
      pcVar1 = zcl_packet_intrp_send;
      packet = (zcl_packet_t *)
               __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x238,
                             "zcl_packet_write_variable_attr_value","size <= sizeof(buf)");
      if (packet != (zcl_packet_t *)0x0) {
        pvStack_3c = value;
        uStack_38 = uVar3;
        pcStack_34 = pcVar1;
        zcl_frame_fill_header(packet);
        aeStack_60[0] = (packet->header).src_addr.addr_mode;
        uStack_5e = 0xffff;
        uStack_5c = *(undefined2 *)&(packet->header).dst_addr;
        eStack_5a = (packet->header).dst_addr.u.short_addr;
        eStack_58 = (packet->header).dst_addr.u.group_addr.bcast;
        uStack_56 = *(undefined2 *)((int)&(packet->header).dst_addr.u + 4);
        uStack_54 = *(undefined2 *)((int)&(packet->header).dst_addr.u + 6);
        uStack_52 = (packet->header).profile_id;
        uStack_50 = (packet->header).cluster_id;
        uStack_4e = 0;
        pzStack_4c = zcl_packet_transfer_ownership(packet);
        if (extraout_a1 == (undefined4 *)0x0) {
          uStack_48 = 0;
          uStack_44 = 0;
        }
        else {
          uStack_48 = *extraout_a1;
          uStack_44 = extraout_a1[1];
        }
        af_intrp_data_request(aeStack_60);
        err_to_zcl_status();
      }
      return;
    }
    zcl_write_attr_value(&local_30,value,uVar3);
    zmsg_write_bytes(payload,CONCAT22(in_register_0000202e,offset),uVar4,&local_30);
  }
  else {
    uVar3 = zcl_get_attr_value_size(uVar3,value);
    zmsg_write_bytes(payload,CONCAT22(in_register_0000202e,offset),uVar3,value);
  }
  return;
}

