/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.release -> zdo_management.o -> zdo_mgmt_task
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

void zdo_mgmt_task(void)

{
  short sVar1;
  int *piVar2;
  short *psVar3;
  int iVar4;
  uint uVar5;
  
  iVar4 = core_globals_get();
  piVar2 = *(int **)(iVar4 + 0xce0);
  while( true ) {
    psVar3 = (short *)(piVar2 + -1);
    if (psVar3 == (short *)0xfffffffc) {
      return;
    }
    if ((piVar2[7] & 1U) == 0) break;
    piVar2 = (int *)*piVar2;
  }
  *(byte *)(piVar2 + 7) = *(byte *)(piVar2 + 7) | 1;
  sVar1 = *psVar3;
  if (sVar1 == 0x36) {
    iVar4 = zdo_dev_joined();
    uVar5 = 0xd;
    if (iVar4 != 0) {
      uVar5 = nwk_permit_joining(*(undefined1 *)(piVar2 + 1));
    }
  }
  else {
    if (sVar1 == 0x38) goto _L0;
    if (sVar1 == 0x34) {
      uVar5 = nwk_leave_request(piVar2 + 1);
      if (uVar5 == 0) goto _L0;
    }
    else {
      uVar5 = 6;
    }
  }
  iVar4 = core_globals_get();
  list_remove_node(iVar4 + 0xce0,piVar2);
  zdo_mgmt_req_finish(psVar3,uVar5 & 0xff);
_L0:
  iVar4 = core_globals_get();
  tasklet_post(iVar4 + 0xce4);
  return;
}

