/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> zcl_packet.o -> zcl_packet_append_variable_attr_value
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_err_t zcl_packet_append_variable_attr_value
                    (zcl_packet_payload_t *payload,uint8_t attr_type,void *value)

{
  code *pcVar1;
  int iVar2;
  undefined4 uVar3;
  ezb_err_t eVar4;
  uint uVar5;
  undefined4 uVar6;
  zcl_packet_t *packet;
  undefined3 in_register_0000202d;
  undefined4 extraout_a1;
  undefined4 *extraout_a1_00;
  char *pcVar7;
  char *pcVar8;
  ezb_addr_mode_t aeStack_90 [2];
  undefined2 uStack_8e;
  undefined2 uStack_8c;
  ezb_shortaddr_t eStack_8a;
  ezb_shortaddr_t eStack_88;
  undefined2 uStack_86;
  undefined2 uStack_84;
  uint16_t uStack_82;
  uint16_t uStack_80;
  undefined1 uStack_7e;
  zmsg_t *pzStack_7c;
  undefined4 uStack_78;
  undefined4 uStack_74;
  char *pcStack_6c;
  char *pcStack_68;
  code *pcStack_64;
  undefined4 uStack_60;
  undefined4 uStack_5c;
  undefined4 uStack_58;
  undefined4 uStack_54;
  undefined4 local_30;
  uint8_t buf [16];
  
  uVar3 = CONCAT31(in_register_0000202d,attr_type);
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
    uVar5 = zcl_get_attr_value_size(uVar3,0);
    if (0x10 < uVar5) {
      pcVar8 = "size <= sizeof(buf)";
      pcVar7 = "zcl_packet_append_variable_attr_value";
      uVar3 = __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x21e);
      uStack_60 = 0;
      uStack_5c = 0;
      uStack_58 = 0;
      uStack_54 = 0;
      iVar2 = zcl_attr_type_is_composite(pcVar7);
      if (iVar2 == 0) {
        uVar5 = zcl_get_attr_value_size(pcVar7,0);
        if (0x10 < uVar5) {
          pcVar1 = zcl_packet_intrp_send;
          packet = (zcl_packet_t *)
                   __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zcl/zcl_packet.c",0x22e
                                 ,"zcl_packet_write_variable_attr_value","size <= sizeof(buf)");
          if (packet == (zcl_packet_t *)0x0) {
            eVar4 = 0x87;
          }
          else {
            pcStack_6c = pcVar8;
            pcStack_68 = pcVar7;
            pcStack_64 = pcVar1;
            zcl_frame_fill_header(packet);
            aeStack_90[0] = (packet->header).src_addr.addr_mode;
            uStack_8e = 0xffff;
            uStack_8c = *(undefined2 *)&(packet->header).dst_addr;
            eStack_8a = (packet->header).dst_addr.u.short_addr;
            eStack_88 = (packet->header).dst_addr.u.group_addr.bcast;
            uStack_86 = *(undefined2 *)((int)&(packet->header).dst_addr.u + 4);
            uStack_84 = *(undefined2 *)((int)&(packet->header).dst_addr.u + 6);
            uStack_82 = (packet->header).profile_id;
            uStack_80 = (packet->header).cluster_id;
            uStack_7e = 0;
            pzStack_7c = zcl_packet_transfer_ownership(packet);
            if (extraout_a1_00 == (undefined4 *)0x0) {
              uStack_78 = 0;
              uStack_74 = 0;
            }
            else {
              uStack_78 = *extraout_a1_00;
              uStack_74 = extraout_a1_00[1];
            }
            af_intrp_data_request(aeStack_90);
            eVar4 = err_to_zcl_status();
          }
          return eVar4;
        }
        zcl_write_attr_value(&uStack_60,pcVar8,pcVar7);
        eVar4 = zmsg_write_bytes(uVar3,extraout_a1,uVar5,&uStack_60);
      }
      else {
        uVar6 = zcl_get_attr_value_size(pcVar7,pcVar8);
        eVar4 = zmsg_write_bytes(uVar3,extraout_a1,uVar6,pcVar8);
      }
      return eVar4;
    }
    zcl_write_attr_value(&local_30,value,uVar3);
    eVar4 = zmsg_append_bytes(payload,uVar5,&local_30);
  }
  else {
    uVar3 = zcl_get_attr_value_size(uVar3,value);
    eVar4 = zmsg_append_bytes(payload,uVar3,value);
  }
  return eVar4;
}

