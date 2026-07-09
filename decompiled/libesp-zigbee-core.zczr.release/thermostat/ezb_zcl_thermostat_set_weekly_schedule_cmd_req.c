/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> thermostat.o -> ezb_zcl_thermostat_set_weekly_schedule_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int ezb_zcl_thermostat_set_weekly_schedule_cmd_req(void *param_1)

{
  int iVar1;
  uint uVar2;
  int iVar3;
  undefined1 auStack_60 [24];
  undefined1 auStack_48 [36];
  undefined4 uStack_24;
  
  memset(auStack_48,0,0x28);
  if ((param_1 == (void *)0x0) || (iVar1 = zcl_packet_init(auStack_48,0), iVar1 != 0)) {
    iVar1 = -1;
  }
  else {
    memcpy(auStack_60,param_1,10);
    iVar1 = zcl_cmd_to_packet(auStack_48,1,0,0,*(undefined1 *)((int)param_1 + 0xc),0,0x201);
    if ((((iVar1 == 0) &&
         (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x18)), iVar1 == 0)) &&
        (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x19)), iVar1 == 0)) &&
       (iVar1 = zmsg_append_u8(uStack_24,*(undefined1 *)((int)param_1 + 0x1a)), iVar1 == 0)) {
      uVar2 = 0;
      do {
        if (((uint)*(byte *)((int)param_1 + 0x18) <= (uVar2 & 0xff)) ||
           (*(int *)((int)param_1 + 0x1c) == 0)) break;
        iVar3 = uVar2 * 6;
        iVar1 = zmsg_append_le16(uStack_24,*(undefined2 *)(*(int *)((int)param_1 + 0x1c) + iVar3));
        if (((iVar1 != 0) ||
            (((*(byte *)((int)param_1 + 0x1a) & 1) != 0 &&
             (iVar1 = zmsg_append_le16(uStack_24,
                                       *(undefined2 *)(*(int *)((int)param_1 + 0x1c) + iVar3 + 2)),
             iVar1 != 0)))) ||
           (((*(byte *)((int)param_1 + 0x1a) & 2) != 0 &&
            (iVar1 = zmsg_append_le16(uStack_24,
                                      *(undefined2 *)(*(int *)((int)param_1 + 0x1c) + iVar3 + 4)),
            iVar1 != 0)))) goto _L0;
        uVar2 = uVar2 + 1;
      } while (uVar2 != 10);
      zcl_packet_send(auStack_48,(int)param_1 + 0x10);
      iVar1 = zcl_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
    }
  }
_L0:
  zcl_packet_free(auStack_48);
  return iVar1;
}

