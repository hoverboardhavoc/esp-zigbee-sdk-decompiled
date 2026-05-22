/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.debug -> ota_upgrade_srv.o -> ota_upgrade_cluster_srv_upgrade_end_req_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

ezb_zcl_status_t
ota_upgrade_cluster_srv_upgrade_end_req_handler(zcl_packet_t *packet,zcl_packet_t *rsp)

{
  undefined4 uVar1;
  ezb_zcl_status_t eVar2;
  uint uVar3;
  int iVar4;
  uint16_t *offset_00;
  undefined1 auStack_38 [8];
  ota_upgrade_upgrade_end_req_payload_t payload;
  ezb_zcl_ota_upgrade_server_progress_upgrade_time_t time;
  uint16_t offset;
  
  time.upgrade_time = 0;
  payload.file_version = 0;
  auStack_38._4_4_ = 0;
  payload.status = '\0';
  payload._1_1_ = 0;
  payload.manuf_code = 0;
  payload.image_type = 0;
  payload._6_2_ = 0;
  if ((packet == (zcl_packet_t *)0x0) || (rsp == (zcl_packet_t *)0x0)) {
    __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/api/zcl/cluster/ota_upgrade_srv.c",
                  0x18d,"ota_upgrade_cluster_srv_upgrade_end_req_handler","packet && rsp");
  }
  else {
    uVar3 = zmsg_get_length(packet->payload);
    offset_00 = &time.upgrade_time;
    af_read_le8(packet->payload,offset_00,auStack_38 + 4);
    af_read_le16(packet->payload,offset_00,(uint16_t *)(auStack_38 + 6));
    af_read_le16(packet->payload,offset_00,(uint16_t *)&payload);
    af_read_le32(packet->payload,offset_00,(uint32_t *)&payload.image_type);
    if (time.upgrade_time <= uVar3) {
      zcl_message_ota_upgrade_server_progress(packet,'\x05',auStack_38 + 4,&payload.file_version);
      if (auStack_38[4] == '\0') {
        auStack_38._0_2_ = auStack_38._6_2_;
        iVar4 = zmsg_append_bytes(rsp->payload,2,auStack_38);
        uVar1 = payload._0_4_;
        if (iVar4 == 0) {
          auStack_38[0] = payload.status;
          auStack_38[1] = payload._1_1_;
          payload._0_4_ = uVar1;
          iVar4 = zmsg_append_bytes(rsp->payload,2,auStack_38);
          if (iVar4 == 0) {
            auStack_38._0_4_ = payload._4_4_;
            iVar4 = zmsg_append_bytes(rsp->payload,4,auStack_38);
            if (iVar4 == 0) {
              auStack_38._0_4_ = payload.file_version & 0xffff;
              iVar4 = zmsg_append_bytes(rsp->payload,4,auStack_38);
              if (iVar4 == 0) {
                auStack_38._0_4_ = payload.file_version >> 0x10;
                zmsg_append_bytes(rsp->payload,4,auStack_38);
              }
            }
          }
        }
      }
      if ((auStack_38._4_4_ & 0xff) != 0) {
        eVar2 = zcl_packet_setup_default_response(rsp,packet,0);
        return eVar2;
      }
      eVar2 = zcl_packet_setup_response_with_extension(rsp,packet,7,0,1);
      return eVar2;
    }
  }
  eVar2 = zcl_packet_setup_default_response(rsp,packet,0x80);
  return eVar2;
}

