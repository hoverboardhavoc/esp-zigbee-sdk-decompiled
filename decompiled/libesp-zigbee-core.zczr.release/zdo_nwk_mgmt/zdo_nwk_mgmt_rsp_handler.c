/*
 * Last changed at upstream commit 02e71c61b42f2e0f80074362fea601f2245ed9d0
 * https://github.com/espressif/esp-zigbee-sdk/commit/02e71c61b42f2e0f80074362fea601f2245ed9d0
 * Upstream date: 2026-04-16 12:25:02 +0800
 * Upstream subject: change: update esp-zigbee-lib 2.x (bce53822)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: notify */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_rsp_handler(void *arg)

{
  ushort uVar1;
  uint16_t uVar2;
  zdp_status_t zVar3;
  uint uVar4;
  int iVar5;
  undefined3 extraout_var;
  uint16_t *puVar6;
  zmsg_t *payload;
  uint16_t auStack_3c [2];
  uint16_t offset;
  uint8_t uStack_36;
  uint8_t uStack_35;
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  if (arg == (void *)0x0) {
    return 0x80;
  }
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 != 0x8034) {
    if (uVar1 < 0x8035) {
      if (uVar1 == 0x8031) {
        zVar3 = zdo_nwk_mgmt_lqi_rsp_handler((zdo_packet_t *)arg);
        return zVar3;
      }
      if (uVar1 != 0x8033) {
        return 0x84;
      }
      offset._0_1_ = '\0';
      offset._1_1_ = '\0';
      uStack_36 = '\0';
      uStack_35 = '\0';
      notify.status = '\0';
      notify._1_3_ = 0;
      if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
         (zVar3 = zdo_op_nwk_mgmt_bind_rsp
                            (*(zdo_packet_payload_t **)((int)arg + 0x14),
                             (zdp_nwk_mgmt_bind_rsp_field_t *)&offset,false),
         CONCAT31(extraout_var,zVar3) != 0)) {
        zVar3 = 0xfe;
      }
      else {
        zdo_packet_notify_result((int)arg + 8,0,&offset);
        zVar3 = '\0';
      }
      if (notify._0_4_ != 0) {
        mm_free();
        return zVar3;
      }
      return zVar3;
    }
    if (uVar1 != 0x8036) {
      if (uVar1 != 0x8038) {
        return 0x84;
      }
      auStack_3c[0] = 0;
      memset(&offset,0,0x28);
      if (*(int *)((int)arg + 0x14) == 0) {
        return 0xfe;
      }
      uVar4 = zmsg_get_length();
      af_read_le8(*(zmsg_t **)((int)arg + 0x14),auStack_3c,(uint8_t *)&offset);
      uVar2 = auStack_3c[0];
      iVar5 = zmsg_read_bytes(*(undefined4 *)((int)arg + 0x14),auStack_3c[0],4,&notify);
      if (iVar5 == 0) {
        auStack_3c[0] = 0xffff;
      }
      else {
        auStack_3c[0] = uVar2 + (short)iVar5;
      }
      af_read_le16(*(zmsg_t **)((int)arg + 0x14),auStack_3c,(uint16_t *)&notify.scanned_channels);
      af_read_le16(*(zmsg_t **)((int)arg + 0x14),auStack_3c,
                   (uint16_t *)((int)&notify.scanned_channels + 2));
      af_read_le8(*(zmsg_t **)((int)arg + 0x14),auStack_3c,(uint8_t *)&notify.total_transmissions);
      af_read_bytes(*(zmsg_t **)((int)arg + 0x14),auStack_3c,
                    (ushort)(byte)notify.total_transmissions,
                    (uint8_t *)((int)&notify.total_transmissions + 1));
      if (uVar4 < auStack_3c[0]) {
        return 0xfe;
      }
      puVar6 = &offset;
      goto _L347;
    }
  }
  auStack_3c[0] = auStack_3c[0] & 0xff00;
  payload = *(zmsg_t **)((int)arg + 0x14);
  if (payload != (zmsg_t *)0x0) {
    _offset = _offset & 0xffff0000;
    uVar4 = zmsg_get_length(payload);
    af_read_le8(payload,&offset,(uint8_t *)auStack_3c);
    puVar6 = auStack_3c;
    if ((_offset & 0xffff) <= uVar4) {
_L347:
      zdo_packet_notify_result((int)arg + 8,0,puVar6);
      return '\0';
    }
  }
  return 0xfe;
}

