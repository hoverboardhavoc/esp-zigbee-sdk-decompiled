/*
 * Last changed at upstream commit 9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * https://github.com/espressif/esp-zigbee-sdk/commit/9bb2fbe73d004aaf258c1dadba7f98d929fbdfc8
 * Upstream date: 2026-07-01 11:36:50 +0800
 * Upstream subject: change: update esp-zigbee-lib (9401bce7)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_rsp_handler(void *arg)

{
  ushort uVar1;
  int iVar2;
  zmsg_t *pzVar3;
  zdp_status_t zVar4;
  undefined3 extraout_var;
  uint uVar5;
  undefined3 extraout_var_00;
  uint uVar6;
  byte bStack_4d;
  undefined1 auStack_4c [3];
  uint8_t status_info;
  uint16_t offset;
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  if (arg == (void *)0x0) {
    iVar2 = 0x80;
    goto _L0;
  }
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 != 0x8034) {
    if (uVar1 < 0x8035) {
      if (uVar1 == 0x8032) {
        pzVar3 = *(zmsg_t **)((int)arg + 0x14);
        _offset = (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0;
        notify.status = '\0';
        notify._1_3_ = 0;
        if (pzVar3 == (zmsg_t *)0x0) goto _L0;
        auStack_4c._0_2_ = 0;
        uVar5 = zmsg_get_length(pzVar3);
        af_read_le8(pzVar3,(uint16_t *)auStack_4c,(uint8_t *)&offset);
        if (((uint)_offset & 0xff) == 0) {
          af_read_le8(pzVar3,(uint16_t *)auStack_4c,(uint8_t *)((int)&offset + 1));
          af_read_le8(pzVar3,(uint16_t *)auStack_4c,&stack0xffffffba);
          af_read_le8(pzVar3,(uint16_t *)auStack_4c,&stack0xffffffbb);
          if (uVar5 < (ushort)auStack_4c._0_2_) goto _L0;
          if ((uint)_offset >> 0x18 != 0) {
            notify._0_4_ = calloc((uint)_offset >> 0x18,6);
            uVar6 = 0;
            if ((void *)notify._0_4_ == (void *)0x0) goto _L0;
            for (; uVar6 < (uint)_offset >> 0x18; uVar6 = uVar6 + 1 & 0xff) {
              iVar2 = uVar6 * 6;
              bStack_4d = 0;
              af_read_le16(pzVar3,(uint16_t *)auStack_4c,(uint16_t *)(notify._0_4_ + iVar2));
              af_read_le8(pzVar3,(uint16_t *)auStack_4c,&bStack_4d);
              af_read_le16(pzVar3,(uint16_t *)auStack_4c,(uint16_t *)(notify._0_4_ + iVar2 + 4));
              if (uVar5 < (ushort)auStack_4c._0_2_) goto _L0;
              *(byte *)(notify._0_4_ + iVar2 + 2) =
                   bStack_4d & 0x3f | *(byte *)(notify._0_4_ + iVar2 + 2) & 0xc0;
            }
          }
        }
        zdo_cb_nwk_mgmt_lqi_rsp
                  ((zdp_nwk_mgmt_lqi_rsp_field_t *)&offset,(zdo_packet_ctx_t *)((int)arg + 8));
        iVar2 = 0;
      }
      else {
        if (uVar1 != 0x8033) {
          if (uVar1 == 0x8031) {
            zVar4 = zdo_nwk_mgmt_lqi_rsp_handler((zdo_packet_t *)arg);
            return zVar4;
          }
          goto _L465;
        }
        _offset = (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)0x0;
        notify.status = '\0';
        notify._1_3_ = 0;
        if (*(zdo_packet_payload_t **)((int)arg + 0x14) != (zdo_packet_payload_t *)0x0) {
          zVar4 = zdo_op_nwk_mgmt_bind_rsp
                            (*(zdo_packet_payload_t **)((int)arg + 0x14),
                             (zdp_nwk_mgmt_bind_rsp_field_t *)&offset,false);
          if (CONCAT31(extraout_var_00,zVar4) == 0) {
            zdo_cb_nwk_mgmt_lqi_rsp
                      ((zdp_nwk_mgmt_lqi_rsp_field_t *)&offset,(zdo_packet_ctx_t *)((int)arg + 8));
            iVar2 = 0;
            goto _L0;
          }
        }
_L0:
        iVar2 = 0xfe;
      }
_L0:
      if (notify._0_4_ != 0) {
        mm_free();
      }
      goto _L0;
    }
    if (uVar1 != 0x8036) {
      if (uVar1 == 0x8038) {
        memset(&offset,0,0x28);
        iVar2 = 0xfe;
        if (*(zdo_packet_payload_t **)((int)arg + 0x14) != (zdo_packet_payload_t *)0x0) {
          zVar4 = zdo_op_nwk_mgmt_nwk_update_notify
                            (*(zdo_packet_payload_t **)((int)arg + 0x14),
                             (zdp_nwk_mgmt_nwk_update_notify_field_t *)&offset,false);
          iVar2 = CONCAT31(extraout_var,zVar4);
          if (iVar2 == 0) {
            zdo_cb_nwk_mgmt_lqi_rsp
                      ((zdp_nwk_mgmt_lqi_rsp_field_t *)&offset,(zdo_packet_ctx_t *)((int)arg + 8));
          }
        }
        goto _L0;
      }
_L465:
      iVar2 = 0x84;
      goto _L0;
    }
  }
  auStack_4c._0_2_ = auStack_4c._0_2_ & 0xff00;
  pzVar3 = *(zmsg_t **)((int)arg + 0x14);
  if (pzVar3 != (zmsg_t *)0x0) {
    _offset = (ezb_zdp_nwk_mgmt_lqi_neighbor_table_entry_t *)((uint)_offset & 0xffff0000);
    uVar5 = zmsg_get_length(pzVar3);
    af_read_le8(pzVar3,&offset,auStack_4c);
    if (((uint)_offset & 0xffff) <= uVar5) {
      zdo_cb_nwk_mgmt_lqi_rsp
                ((zdp_nwk_mgmt_lqi_rsp_field_t *)auStack_4c,(zdo_packet_ctx_t *)((int)arg + 8));
      iVar2 = 0;
      goto _L0;
    }
  }
  iVar2 = 0xfe;
_L0:
  return (zdp_status_t)iVar2;
}

