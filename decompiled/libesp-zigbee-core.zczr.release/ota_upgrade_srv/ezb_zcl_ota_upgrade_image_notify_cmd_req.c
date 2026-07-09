/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> ota_upgrade_srv.o -> ezb_zcl_ota_upgrade_image_notify_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_ota_upgrade_image_notify_cmd_req(void *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  undefined1 auStack_50 [23];
  undefined1 uStack_39;
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar3 = zcl_packet_init(auStack_38,0), iVar3 != 0)) {
    iVar3 = -1;
    goto _L0;
  }
  memcpy(auStack_50,param_1,10);
  iVar3 = zcl_cmd_to_packet(auStack_38,1,0,1,*(undefined1 *)((int)param_1 + 0xc),0,0,0x19);
  if (iVar3 != 0) goto _L0;
  uStack_39 = *(undefined1 *)((int)param_1 + 0x18);
  iVar3 = zmsg_append_bytes(uStack_14,1,&uStack_39);
  if (iVar3 != 0) goto _L0;
  uStack_39 = *(undefined1 *)((int)param_1 + 0x19);
  iVar3 = zmsg_append_bytes(uStack_14,1,&uStack_39);
  if (iVar3 != 0) goto _L0;
  cVar1 = *(char *)((int)param_1 + 0x18);
  if (cVar1 == '\x03') {
    iVar3 = zmsg_append_le16(uStack_14,*(undefined2 *)((int)param_1 + 0x1a));
    if ((iVar3 != 0) ||
       (iVar3 = zmsg_append_le16(uStack_14,*(undefined2 *)((int)param_1 + 0x1c)), iVar3 != 0))
    goto _L0;
    iVar3 = zmsg_append_le32(uStack_14,*(undefined4 *)((int)param_1 + 0x20));
_L187:
    if (iVar3 != 0) goto _L0;
  }
  else {
    if (cVar1 == '\x02') {
      iVar3 = zmsg_append_le16(uStack_14,*(undefined2 *)((int)param_1 + 0x1a));
      if (iVar3 != 0) goto _L0;
      uVar2 = *(undefined2 *)((int)param_1 + 0x1c);
_L0:
      iVar3 = zmsg_append_le16(uStack_14,uVar2);
      goto _L187;
    }
    if (cVar1 == '\x01') {
      uVar2 = *(undefined2 *)((int)param_1 + 0x1a);
      goto _L0;
    }
  }
  zcl_packet_send(auStack_38,(int)param_1 + 0x10);
  iVar3 = zcl_status_to_err();
  if (iVar3 == 0) {
    return 0;
  }
_L0:
  zcl_packet_free(auStack_38);
  return iVar3;
}

