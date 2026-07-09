/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_parent_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_parent_annce_req(ushort *param_1)

{
  int iVar1;
  char cVar2;
  int iVar3;
  undefined4 local_40;
  undefined4 uStack_3c;
  undefined1 auStack_38 [20];
  undefined4 uStack_24;
  
  memset(auStack_38,0,0x18);
  if ((param_1 == (ushort *)0x0) || ((*param_1 != 0xfffc && (0xfff7 < *param_1)))) {
    iVar1 = 2;
  }
  else {
    iVar3 = zdo_packet_init(auStack_38,0x1f,*(undefined4 *)(param_1 + 2),
                            *(undefined4 *)(param_1 + 4));
    iVar1 = -1;
    if (iVar3 == 0) {
      iVar1 = nwk_is_device_zczr();
      if (iVar1 != 0) {
        iVar1 = zmsg_append_u8(uStack_24,0);
        if (iVar1 != 0) goto _L0;
        iVar3 = 0;
        cVar2 = '\0';
        while (iVar3 = nwk_neighbor_table_next(iVar3), iVar3 != 0) {
          if ((*(uint *)(iVar3 + 0xc) & 3) == 2) {
            local_40 = 0;
            uStack_3c = 0;
            nwk_neighbor_get_extaddr(&local_40);
            iVar1 = zmsg_append_bytes(uStack_24,8,&local_40);
            if (iVar1 != 0) goto _L0;
            cVar2 = cVar2 + '\x01';
          }
        }
        local_40 = CONCAT31(local_40._1_3_,cVar2);
        zmsg_write_bytes(uStack_24,0,1,&local_40);
        if (cVar2 != '\0') {
          zdo_packet_send(auStack_38);
          iVar1 = zdp_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
      iVar1 = 5;
    }
  }
_L0:
  zdo_packet_free(auStack_38);
  return iVar1;
}

