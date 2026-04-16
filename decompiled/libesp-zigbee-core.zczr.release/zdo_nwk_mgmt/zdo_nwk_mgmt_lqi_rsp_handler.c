/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_lqi_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: rsp */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_lqi_rsp_handler(zdo_packet_t *packet)

{
  zdp_status_t zVar1;
  zmsg_t *payload;
  uint uVar2;
  uint uVar3;
  int iVar4;
  byte bStack_2c;
  byte bStack_2b;
  uint16_t uStack_2a;
  uint8_t dev_info;
  uint8_t state_info;
  uint16_t offset;
  zdp_nwk_mgmt_lqi_rsp_field_t rsp;
  
  _dev_info = 0;
  rsp.status = '\0';
  rsp.neighbor_table_entries = '\0';
  rsp.start_index = '\0';
  rsp.neighbor_table_list_count = '\0';
  if ((packet != (zdo_packet_t *)0x0) && (payload = packet->payload, payload != (zmsg_t *)0x0)) {
    uStack_2a = 0;
    uVar3 = zmsg_get_length(payload);
    af_read_le8(payload,&uStack_2a,&dev_info);
    af_read_le8(payload,&uStack_2a,&state_info);
    af_read_le8(payload,&uStack_2a,(uint8_t *)&offset);
    af_read_le8(payload,&uStack_2a,(uint8_t *)((int)&offset + 1));
    if (uStack_2a <= uVar3) {
      if (((_dev_info & 0xff) == 0) && (_dev_info >> 0x18 != 0)) {
        rsp._0_4_ = calloc(_dev_info >> 0x18,0x16);
        uVar2 = 0;
        if ((void *)rsp._0_4_ == (void *)0x0) goto _L0;
        for (; uVar2 < _dev_info >> 0x18; uVar2 = uVar2 + 1 & 0xff) {
          iVar4 = uVar2 * 0x16;
          bStack_2c = 0;
          bStack_2b = 0;
          af_read_bytes(payload,&uStack_2a,8,(uint8_t *)(rsp._0_4_ + iVar4));
          af_read_bytes(payload,&uStack_2a,8,(uint8_t *)(rsp._0_4_ + iVar4 + 8));
          af_read_le16(payload,&uStack_2a,(uint16_t *)(rsp._0_4_ + iVar4 + 0x10));
          af_read_le8(payload,&uStack_2a,&bStack_2c);
          af_read_le8(payload,&uStack_2a,&bStack_2b);
          af_read_le8(payload,&uStack_2a,(uint8_t *)(rsp._0_4_ + iVar4 + 0x14));
          af_read_le8(payload,&uStack_2a,(uint8_t *)(rsp._0_4_ + iVar4 + 0x15));
          if (uVar3 < uStack_2a) goto _L0;
          *(ushort *)(rsp._0_4_ + iVar4 + 0x12) =
               bStack_2c & 0x7f | (ushort)((bStack_2b & 3) << 8) |
               *(ushort *)(rsp._0_4_ + iVar4 + 0x12) & 0xfc80;
        }
      }
      zdo_packet_notify_result(&packet->ctx,0,&dev_info);
      zVar1 = '\0';
      goto _L0;
    }
  }
_L0:
  zVar1 = 0xfe;
_L0:
  if (rsp._0_4_ != 0) {
    mm_free();
  }
  return zVar1;
}

