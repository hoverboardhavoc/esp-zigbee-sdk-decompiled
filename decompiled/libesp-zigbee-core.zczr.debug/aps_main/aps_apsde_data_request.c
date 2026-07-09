/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> aps_main.o -> aps_apsde_data_request
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

int aps_apsde_data_request(int *param_1)

{
  byte bVar1;
  undefined2 uVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined2 uStack_28;
  undefined2 uStack_26;
  int iStack_24;
  uint uStack_20;
  code *pcStack_1c;
  int iStack_18;
  undefined2 local_12;
  
  piVar3 = param_1;
  if (param_1 == (int *)0x0) {
_L0:
    iVar5 = 2;
    goto _L0;
  }
  piVar3 = (int *)*param_1;
  if (piVar3 == (int *)0x0) {
    iVar5 = 2;
    goto _L0;
  }
  bVar1 = *(byte *)(param_1 + 1);
  if (bVar1 == 2) {
    uVar2 = *(undefined2 *)((int)param_1 + 6);
_L0:
    local_12 = uVar2;
    iVar5 = apsde_data_request_continue(param_1,local_12);
  }
  else {
    if (2 < bVar1) {
      if (bVar1 != 3) {
        iVar5 = 2;
        goto _L0;
      }
      iVar5 = nwk_address_short_by_extended((int)param_1 + 6,&local_12);
      uVar2 = local_12;
      if (iVar5 != 0) {
        zmsg_add_footer(piVar3,param_1,0x1c);
        iStack_24 = param_1[2];
        _uStack_28 = CONCAT22(*(undefined2 *)((int)param_1 + 6),0xffff);
        uStack_20 = (uint)*(ushort *)(param_1 + 3);
        pcStack_1c = apsde_handle_nwk_addr_req_result;
        iStack_18 = (int)piVar3;
        iVar5 = zdo_nwk_addr_req(&uStack_28);
        if (iVar5 == 0) {
          return 0;
        }
        iVar5 = 0x3a9;
        goto _L0;
      }
      goto _L0;
    }
    if (bVar1 != 0) {
      if (bVar1 != 1) {
        iVar5 = 2;
        goto _L0;
      }
      iVar5 = param_1[2];
      iVar4 = aps_is_shortaddr_bcast((short)iVar5);
      uVar2 = (short)iVar5;
      if (iVar4 == 0) {
        iVar5 = 2;
        goto _L0;
      }
      goto _L0;
    }
    if ((*(ushort *)((int)piVar3 + 0x16) & 0x20) != 0) {
      piVar3 = (int *)__assert_func("//builds/thread_zigbee/esp-zigbee/src/core/aps/aps_main.c",
                                    0x2cc,"aps_apsde_data_request",
                                    "!zmsg_test_flag(msg, ((1 << ((5) % (sizeof(unsigned long) * 8)))))"
                                   );
      goto _L0;
    }
    iVar5 = aps_bind_trans_request();
  }
  if (iVar5 == 0) {
    return 0;
  }
_L0:
  if (piVar3 != (int *)0x0) {
    zmsg_free(piVar3);
  }
  return iVar5;
}

