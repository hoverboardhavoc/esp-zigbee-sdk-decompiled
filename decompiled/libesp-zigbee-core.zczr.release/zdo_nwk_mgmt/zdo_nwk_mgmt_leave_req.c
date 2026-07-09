/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_nwk_mgmt.o -> zdo_nwk_mgmt_leave_req
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int zdo_nwk_mgmt_leave_req(undefined2 *param_1)

{
  int iVar1;
  int iVar2;
  undefined2 *puVar3;
  uint unaff_s2;
  undefined1 auStack_28 [20];
  int iStack_14;
  
  memset(auStack_28,0,0x18);
  if (param_1 == (undefined2 *)0x0) {
    iVar1 = 2;
    goto _L0;
  }
  iVar2 = zdo_packet_init(auStack_28,0x34,*param_1,*(undefined4 *)(param_1 + 6),
                          *(undefined4 *)(param_1 + 8));
  iVar1 = -1;
  if (iVar2 != 0) goto _L0;
  puVar3 = param_1 + 1;
  if (iStack_14 == 0) {
    __assert_func(0,0,0);
_L0:
    iVar1 = zmsg_append_u8(iStack_14,((int)param_1 << 7 | unaff_s2 << 6) & 0xc0);
    if (iVar1 == 0) {
      zdo_packet_send(auStack_28);
      iVar1 = zdp_status_to_err();
      if (iVar1 == 0) {
        return 0;
      }
      goto _L0;
    }
  }
  else {
    unaff_s2 = (uint)*(byte *)(param_1 + 5);
    param_1 = (undefined2 *)(uint)*(byte *)((int)param_1 + 0xb);
    iVar1 = zmsg_append_bytes(iStack_14,8,puVar3);
    if (iVar1 == 0) goto _L0;
  }
  iVar1 = 1;
_L0:
  zdo_packet_free(auStack_28);
  return iVar1;
}

