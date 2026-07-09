/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> aps_commands.o -> aps_send_cmd
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void aps_send_cmd(undefined4 param_1,int *param_2)

{
  byte bVar1;
  uint uVar2;
  int iVar3;
  byte bStack_2f;
  undefined2 uStack_2e;
  undefined4 uStack_2c;
  undefined1 auStack_28 [20];
  byte bStack_14;
  
  uVar2 = zmsg_get_length();
  if (0x5a < uVar2) {
    __assert_func(0,0,0,0);
  }
  memset(auStack_28,0,0x18);
  uStack_2c = param_1;
  zmsg_read_u8(param_1,0,&bStack_2f);
  bVar1 = bStack_14 & 0xfc;
  bStack_14 = bStack_2f >> 5 & 2 | bStack_2f >> 5 & 1 | bVar1;
  if ((*param_2 == -1) && (param_2[1] == -1)) {
    uStack_2e = 0xfffd;
    bStack_14 = bVar1;
  }
  else {
    iVar3 = nwk_address_short_by_extended(param_2,&uStack_2e);
    if (iVar3 != 0) {
      return;
    }
  }
  zmsg_add_footer(param_1,&uStack_2c,0x1c);
  if ((bStack_14 & 2) == 0) {
    aps_send_frame(&uStack_2c);
  }
  else {
    aps_retrans_send_msg(uStack_2e,0x5a,&uStack_2c);
  }
  return;
}

