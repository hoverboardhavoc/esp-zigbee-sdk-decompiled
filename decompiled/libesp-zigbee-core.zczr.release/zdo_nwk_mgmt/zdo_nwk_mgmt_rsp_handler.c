/*
 * Last changed at upstream commit bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * https://github.com/espressif/esp-zigbee-sdk/commit/bc26b7ab9d3ed8b27084676d02ef07f61f4afac6
 * Upstream date: 2026-05-22 03:16:46 +0000
 * Upstream subject: change: update esp-zigbee-lib (73450389)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_rsp_handler
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

/* WARNING: Variable defined which should be unmapped: notify */
/* WARNING: Removing unreachable block (ram,0x000116e6) */
/* WARNING: Unknown calling convention */

zdp_status_t zdo_nwk_mgmt_rsp_handler(void *arg)

{
  ushort uVar1;
  int iVar2;
  zdp_status_t zVar3;
  undefined3 extraout_var;
  uint uVar4;
  undefined3 extraout_var_00;
  zmsg_t *payload;
  uint8_t auStack_3c [4];
  zdp_nwk_mgmt_permit_joining_rsp_field_t rsp;
  undefined3 uStack_37;
  zdp_nwk_mgmt_nwk_update_notify_field_t notify;
  
  if (arg == (void *)0x0) {
    iVar2 = 0x80;
    goto _L0;
  }
  uVar1 = *(ushort *)((int)arg + 6);
  if (uVar1 == 0x8034) {
_L0:
    auStack_3c[0] = '\0';
    payload = *(zmsg_t **)((int)arg + 0x14);
    if (payload != (zmsg_t *)0x0) {
      _rsp = _rsp & 0xffff0000;
      uVar4 = zmsg_get_length(payload);
      af_read_le8(payload,(uint16_t *)&rsp,auStack_3c);
      if ((_rsp & 0xffff) <= uVar4) {
        zdo_packet_notify_result((int)arg + 8,0,auStack_3c);
        iVar2 = 0;
        goto _L0;
      }
    }
    iVar2 = 0xfe;
  }
  else {
    if (uVar1 < 0x8035) {
      if (uVar1 == 0x8031) {
        zVar3 = zdo_nwk_mgmt_lqi_rsp_handler((zdo_packet_t *)arg);
        return zVar3;
      }
      if (uVar1 == 0x8033) {
        rsp.status = '\0';
        uStack_37 = 0;
        if ((*(zdo_packet_payload_t **)((int)arg + 0x14) == (zdo_packet_payload_t *)0x0) ||
           (zVar3 = zdo_op_nwk_mgmt_bind_rsp
                              (*(zdo_packet_payload_t **)((int)arg + 0x14),
                               (zdp_nwk_mgmt_bind_rsp_field_t *)&rsp,false),
           CONCAT31(extraout_var_00,zVar3) != 0)) {
          iVar2 = 0xfe;
        }
        else {
          zdo_packet_notify_result((int)arg + 8,0,&rsp);
          iVar2 = 0;
        }
        goto _L0;
      }
    }
    else {
      if (uVar1 == 0x8036) goto _L0;
      if (uVar1 == 0x8038) {
        memset(&rsp,0,0x28);
        iVar2 = 0xfe;
        if (*(zdo_packet_payload_t **)((int)arg + 0x14) != (zdo_packet_payload_t *)0x0) {
          zVar3 = zdo_op_nwk_mgmt_nwk_update_notify
                            (*(zdo_packet_payload_t **)((int)arg + 0x14),
                             (zdp_nwk_mgmt_nwk_update_notify_field_t *)&rsp,false);
          iVar2 = CONCAT31(extraout_var,zVar3);
          if (iVar2 == 0) {
            zdo_packet_notify_result((int)arg + 8,0,&rsp);
          }
        }
        goto _L0;
      }
    }
    iVar2 = 0x84;
  }
_L0:
  return (zdp_status_t)iVar2;
}

