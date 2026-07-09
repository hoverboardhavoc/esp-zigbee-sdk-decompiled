/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_parent_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_parent_annce_req(ushort *param_1)

{
  int iVar1;
  int iVar2;
  char cVar3;
  uint local_30 [8];
  
  local_30[2] = 0;
  local_30[3] = 0;
  local_30[4] = 0;
  local_30[5] = 0;
  local_30[6] = 0;
  local_30[7] = 0;
  if (param_1 == (ushort *)0x0) {
    iVar2 = 2;
  }
  else if ((*param_1 == 0xfffc) || (*param_1 < 0xfff8)) {
    iVar2 = zdo_packet_init(local_30 + 2,0x1f,*(undefined4 *)(param_1 + 2),
                            *(undefined4 *)(param_1 + 4));
    if (iVar2 == 0) {
      iVar2 = nwk_is_device_zczr();
      if (iVar2 == 0) {
        iVar2 = 5;
      }
      else {
        local_30[0] = local_30[0] & 0xffffff00;
        iVar2 = zmsg_append_bytes(local_30[7],1,local_30);
        if (iVar2 != 0) goto _L0;
        iVar1 = 0;
        cVar3 = '\0';
        while (iVar1 = nwk_neighbor_table_next(iVar1), iVar1 != 0) {
          if ((*(uint *)(iVar1 + 0xc) & 3) == 2) {
            local_30[0] = 0;
            local_30[1] = 0;
            nwk_neighbor_get_extaddr(iVar1,local_30);
            iVar2 = zmsg_append_bytes(local_30[7],8,local_30);
            if (iVar2 != 0) goto _L0;
            cVar3 = cVar3 + '\x01';
          }
        }
        local_30[0] = CONCAT31(local_30[0]._1_3_,cVar3);
        zmsg_write_bytes(local_30[7],0,1,local_30);
        if (cVar3 == '\0') {
          iVar2 = 5;
          goto _L0;
        }
        zdo_packet_send(local_30 + 2);
        iVar2 = zdp_status_to_err();
      }
_L0:
      if (iVar2 == 0) {
        return 0;
      }
    }
    else {
      iVar2 = -1;
    }
  }
  else {
    iVar2 = 2;
  }
_L0:
  zdo_packet_free(local_30 + 2);
  return iVar2;
}

