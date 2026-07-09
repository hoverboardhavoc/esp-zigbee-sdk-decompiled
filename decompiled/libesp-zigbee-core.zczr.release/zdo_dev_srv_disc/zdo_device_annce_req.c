/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_dev_srv_disc.o -> zdo_device_annce_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_device_annce_req(undefined4 *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined1 auStack_28 [20];
  undefined4 uStack_14;
  
  memset(auStack_28,0,0x18);
  if (param_1 == (undefined4 *)0x0) {
    iVar2 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,0x13,0xfffd,*param_1,param_1[1]);
  if (iVar2 == 0) {
    iVar3 = af_get_node_desc();
    if (iVar3 == 0) {
      iVar2 = 5;
      goto _L0;
    }
    iVar4 = nwk_get_extended_address();
    uVar1 = uStack_14;
    if (iVar4 != 0) {
      uVar5 = nwk_get_short_address();
      iVar2 = zmsg_append_le16(uVar1,uVar5);
      if (((iVar2 == 0) && (iVar2 = zmsg_append_bytes(uStack_14,8,iVar4), iVar2 == 0)) &&
         (iVar2 = zmsg_append_u8(uStack_14,*(undefined1 *)(iVar3 + 2)), iVar2 == 0)) {
        zdo_packet_send(auStack_28);
        iVar2 = zdp_status_to_err();
        if (iVar2 == 0) {
          return 0;
        }
      }
      goto _L0;
    }
  }
  iVar2 = -1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar2;
}

