/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zcl_general_cmd.o -> zcl_disc_cmd_cmd_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zcl_disc_cmd_cmd_req(void *param_1)

{
  char cVar1;
  undefined2 uVar2;
  int iVar3;
  uint uVar4;
  undefined1 auStack_50 [24];
  undefined1 auStack_38 [36];
  undefined4 uStack_14;
  
  memset(auStack_38,0,0x28);
  if ((param_1 == (void *)0x0) ||
     (iVar3 = zcl_packet_init(auStack_38,*(uint *)((int)param_1 + 0x10) & 1), iVar3 != 0)) {
    iVar3 = -1;
  }
  else {
    cVar1 = *(char *)((int)param_1 + 0x1c);
    uVar4 = *(uint *)((int)param_1 + 0x10);
    uVar2 = *(undefined2 *)((int)param_1 + 0xe);
    memcpy(auStack_50,param_1,10);
    iVar3 = zcl_cmd_to_packet(auStack_38,0,uVar4 & 1,uVar4 >> 1 & 1,uVar4 >> 2 & 1,uVar2,
                              (cVar1 == '\0') * '\x02' + '\x11',*(undefined2 *)((int)param_1 + 0xc))
    ;
    if (((iVar3 == 0) &&
        (iVar3 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x1e)), iVar3 == 0)) &&
       (iVar3 = zmsg_append_u8(uStack_14,*(undefined1 *)((int)param_1 + 0x20)), iVar3 == 0)) {
      zcl_packet_send(auStack_38,(int)param_1 + 0x14);
      iVar3 = zcl_status_to_err();
      if (iVar3 == 0) {
        return 0;
      }
    }
  }
  zcl_packet_free(auStack_38);
  return iVar3;
}

