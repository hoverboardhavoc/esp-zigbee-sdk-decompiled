/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_parent_annce_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_parent_annce_handler(zdo_packet_t *packet,zdo_packet_t *resp)

{
  uint8_t *value;
  zdp_status_t zVar1;
  int iVar2;
  uint uVar3;
  char cVar4;
  char cStack_2d;
  undefined4 uStack_2c;
  zdp_parent_annce_t req;
  uint16_t offset;
  
  req.child_info.field_0.u64._5_2_ = 0;
  uStack_2c = 0;
  req._0_4_ = 0;
  req.child_info.field_0.u8[3] = '\0';
  if (packet == (zdo_packet_t *)0x0) {
    zVar1 = 0xfe;
  }
  else if (packet->payload == (zdo_packet_payload_t *)0x0) {
    zVar1 = 0xfe;
  }
  else {
    iVar2 = nwk_is_device_zed();
    if (iVar2 == 0) {
      uVar3 = zmsg_get_length(packet->payload);
      af_read_le8(packet->payload,(uint16_t *)(req.child_info.field_0.u8 + 5),(uint8_t *)&uStack_2c)
      ;
      if (uVar3 < (ushort)req.child_info.field_0.u64._5_2_) {
        zVar1 = 0xfe;
      }
      else {
        if ((0xfff7 < packet->dst_addr) &&
           (iVar2 = core_globals_get(), *(char *)(iVar2 + 0x16) != '\0')) {
          uVar3 = random_noncrypto_range_u32(0,0x2711);
          iVar2 = core_globals_get();
          *(char *)(iVar2 + 0x16) = (char)(uVar3 / 1000) + '\n';
        }
        cStack_2d = '\0';
        zmsg_append_bytes(resp->payload,1,&cStack_2d);
        cVar4 = '\0';
        for (uVar3 = 0; uVar3 < (uStack_2c & 0xff); uVar3 = uVar3 + 1 & 0xff) {
          value = (uint8_t *)((int)&uStack_2c + 1);
          af_read_bytes(packet->payload,(uint16_t *)(req.child_info.field_0.u8 + 5),8,value);
          iVar2 = nwk_neighbor_table_get_by_extended(value);
          if (((iVar2 != 0) && ((*(uint *)(iVar2 + 0xc) & 3) == 2)) &&
             (*(int *)(iVar2 + 0x14) << 7 < 0)) {
            zVar1 = zmsg_append_bytes(resp->payload,8,value);
            if (zVar1 != '\0') {
              return zVar1;
            }
            cVar4 = cVar4 + '\x01';
          }
        }
        if (cVar4 == '\0') {
          zVar1 = 0xfe;
        }
        else {
          cStack_2d = cVar4;
          zmsg_write_bytes(resp->payload,0,1,&cStack_2d);
          zVar1 = '\0';
        }
      }
    }
    else {
      zVar1 = 0xfe;
    }
  }
  return zVar1;
}

