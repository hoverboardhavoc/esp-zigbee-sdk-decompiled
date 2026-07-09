/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> price.o -> ezb_zcl_price_publish_tier_labels_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_price_publish_tier_labels_cmd_req(void *param_1)

{
  int iVar1;
  uint uVar2;
  uint uVar3;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar1 = zcl_packet_init(auStack_48,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,param_1,10);
    iVar1 = zcl_cmd_to_packet(auStack_48,1,0,*(undefined1 *)((int)param_1 + 0xc),0,8,0x700);
    if (iVar1 == 0) {
      iVar1 = zmsg_append_le32(uStack_24,*(undefined4 *)((int)param_1 + 0x18));
      if ((((iVar1 == 0) &&
           (iVar1 = zmsg_append_le32(uStack_24,*(undefined4 *)((int)param_1 + 0x1c)), iVar1 == 0))
          && (iVar1 = zmsg_append_le32(uStack_24,*(undefined4 *)((int)param_1 + 0x20)), iVar1 == 0))
         && ((iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x24)), iVar1 == 0 &&
             (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x25)), iVar1 == 0))))
      {
        if ((*(char *)((int)param_1 + 0x26) == '\0') || (*(int *)((int)param_1 + 0x28) == 0)) {
_L0:
          iVar1 = 2;
          goto _L0;
        }
        iVar1 = zmsg_append_u8(uStack_24);
        if (iVar1 == 0) {
          for (uVar3 = 0; uVar3 < *(byte *)((int)param_1 + 0x26); uVar3 = uVar3 + 1 & 0xff) {
            iVar1 = zmsg_append_u8(uStack_24,
                                   *(undefined1 *)(*(int *)((int)param_1 + 0x28) + uVar3 * 0xe));
            if (iVar1 != 0) goto _L0;
            iVar1 = *(int *)((int)param_1 + 0x28) + uVar3 * 0xe;
            uVar2 = (uint)*(byte *)(iVar1 + 1);
            if (0xc < uVar2) goto _L0;
            iVar1 = zmsg_append_bytes(uStack_24,uVar2 + 1,iVar1 + 1);
            if (iVar1 != 0) goto _L0;
          }
          zcl_packet_send(auStack_48,(int)param_1 + 0x10);
          iVar1 = zcl_status_to_err();
          if (iVar1 == 0) {
            return 0;
          }
          goto _L0;
        }
      }
_L0:
      iVar1 = 1;
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}

