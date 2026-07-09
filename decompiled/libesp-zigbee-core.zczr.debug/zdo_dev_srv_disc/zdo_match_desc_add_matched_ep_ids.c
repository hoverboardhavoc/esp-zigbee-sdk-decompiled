/*
 * Last changed at upstream commit 0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * https://github.com/espressif/esp-zigbee-sdk/commit/0dbfa9988ffc315d4d533fc462a8328b10d4d371
 * Upstream date: 2026-07-09 09:00:50 +0000
 * Upstream subject: change: update esp-zigbee-lib (170bcb5a)
 * Source: libesp-zigbee-core.zczr.debug -> zdo_dev_srv_disc.o -> zdo_match_desc_add_matched_ep_ids
 *
 * (C) Espressif, Apache License 2.0.
 * Derivative work (this file): mechanical decompile via Ghidra (NSA, Apache 2.0).
 * Decompiler output may be incomplete or differ from original semantics.
 */

undefined1 zdo_match_desc_add_matched_ep_ids(int param_1,int param_2)

{
  byte bVar1;
  undefined1 uVar2;
  byte bVar3;
  undefined1 *unaff_s0;
  int iVar4;
  int iVar5;
  int iVar6;
  
  if ((param_2 != 0) && (param_1 != 0)) {
    unaff_s0 = (undefined1 *)0x0;
    while (unaff_s0 = (undefined1 *)af_get_next_simple_desc(unaff_s0), unaff_s0 != (undefined1 *)0x0
          ) {
      iVar4 = *(int *)(unaff_s0 + 0xc);
      bVar1 = unaff_s0[7];
      uVar2 = unaff_s0[8];
      if ((*(short *)(unaff_s0 + 2) == *(short *)(param_1 + 2)) || (*(short *)(param_1 + 2) == -1))
      {
        iVar6 = *(int *)(param_1 + 8);
        bVar3 = *(byte *)(param_1 + 4);
        iVar5 = clusters_is_on_list(iVar6,(uint)bVar3);
        if ((iVar5 != 0) ||
           (iVar4 = clusters_is_on_list(iVar4 + (uint)bVar1 * 2,uVar2,(uint)bVar3 * 2 + iVar6,
                                        *(undefined1 *)(param_1 + 5)), iVar4 != 0)) {
_L0:
          bVar1 = *(byte *)(param_2 + 4);
          *(byte *)(param_2 + 4) = bVar1 + 1;
          *(undefined1 *)(*(int *)(param_2 + 8) + (uint)bVar1) = *unaff_s0;
        }
      }
    }
    return *(undefined1 *)(param_2 + 4);
  }
  __assert_func("//builds/thread_zigbee/esp-zigbee/src/core/zdo/zdo_dev_srv_disc.c",999,
                "zdo_match_desc_add_matched_ep_ids","rsp && req");
  goto _L0;
}

